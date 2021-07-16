#pragma once
#include <iostream>
#include <cassert>
#include "printHelper.hpp"

namespace lib {
	template<typename NodeType>
	class LibAllocator {
	public:
		typedef NodeType*	pointer;
		static void* allocate(unsigned int size) {
			return malloc(size);
		}
		static NodeType* construct(void* p,const typename NodeType::UserDataType& msg) {return new(p) NodeType(msg);}
		static void deallocate(pointer p) { 
			//PrintF;
			if(p != nullptr) free(p); 
		}
		static void destruct(pointer p) {
			//PrintF;
			p->~NodeType();
		}
	};
}

namespace detail {

	template<typename InternalObject>
	class IteratorIntf {
	private:
		typedef InternalObject* pointer;
	public:
		typedef typename InternalObject::UserDataType 		UserDataType;
		friend class InternalObject::ContainerType;
	    
	    IteratorIntf(pointer ptr = nullptr):m_ptr(ptr){}
	    ~IteratorIntf(){}

	    operator bool() const {
			if(m_ptr)
				return true;
	        else
				return false;
	    }
	    UserDataType& 			operator*() { return m_ptr->getData(); }
	    const UserDataType& 	operator*() const { return m_ptr->getData();}
	 	
		IteratorIntf&			operator++(){m_ptr = m_ptr->getNext();return (*this);}
	 	IteratorIntf			operator++(int){
	 		IteratorIntf temp(*this);
	 		m_ptr = m_ptr->getNext();
	 		return temp;
	 	}

	 	IteratorIntf&			operator--(){m_ptr = m_ptr->getPrev();return (*this);}
	 	IteratorIntf			operator--(int){
	 		IteratorIntf temp(*this);
	 		m_ptr = m_ptr->getPrev();
	 		return temp;
	 	}
		
		bool					operator==(const IteratorIntf& other)const{return (m_ptr == other.GetPtr());}
    	bool					operator!=(const IteratorIntf& other)const{return (m_ptr != other.GetPtr());}

	private:
		pointer GetPtr() const {
			return m_ptr;
		}
	    pointer m_ptr;
	};

}


namespace lib {

	using namespace detail;


	template<typename Data, template<typename> typename Alloc = LibAllocator>
	class List {
	private:
		template<typename NodeData>
		class Node;
	public:
		typedef List 					ThisContainer;
		typedef Data 					UserDataType;
		typedef Node<UserDataType>  	ListNode;
		typedef Alloc<ListNode>     	Allocator;
		typedef IteratorIntf<ListNode>	Iterator;

		// PUBLIC APIs 
		List():head(nullptr),tail(nullptr),ListSize(0) {}
		
		~List() {
			if(head != nullptr) {
				ListNode * temp = head;
				while(temp != nullptr) {
					head = head->getNext();
					Allocator::destruct(temp);
					Allocator::deallocate(temp);
					temp = head;
				}
			}
		}

		#define INSERT_BEFORE 	true
		#define INSERT_AFTER	false

		void Push_back(const UserDataType& data) {
			ListNode* newNode = __allocate_new_node(data);
			__insert_node_back(newNode);
		}

		UserDataType& Back() const{
			assert(("Back() on empty List is UB", ListSize > 0));
			return tail->getData();
		}

		void Push_front(const UserDataType& data) {
			ListNode* newNode = __allocate_new_node(data);
			__insert_node_front(newNode);
		}

		UserDataType& Front() const {
			assert(("Front() on empty List is UB", ListSize > 0));
			return head->getData();
		}

		void Clear() {
			Iterator iter = this->Begin();
			while(iter) {
				iter = Erase(iter);
			}
		}

		bool Empty() const {
			return ListSize == 0;
		}

		Iterator Erase(Iterator pos) {
			Iterator nextPos;
			if(pos && ListSize > 0) {
				nextPos = pos;
				nextPos++;
				__erase_node(pos.GetPtr());
			}
			return nextPos;
		}

		Iterator Insert(Iterator pos,const UserDataType& data) {
			Iterator insertedLoc;
			if(pos != nullptr) {
				ListNode* newNode = __allocate_new_node(data);
				__insert_node(pos.GetPtr(),newNode,INSERT_BEFORE);
				insertedLoc = --pos;
			}
			return insertedLoc;
		}

		Iterator Begin() const {
			Iterator iter(head);
			return iter;
		}

		Iterator End() const {
			Iterator iter(tail);
			return iter;
		}

		unsigned int Size() const { return ListSize; }
		// END OF PUBLIC APIs 

	private:

		template<typename NodeData>
		class Node {
		public:
			typedef NodeData 		UserDataType;
			typedef ThisContainer	ContainerType;

			Node():next(nullptr),prev(nullptr){}
			Node(const UserDataType& _data):next(nullptr),prev(nullptr),data(_data){}
			
			~Node() {
				//PrintF;
				next = nullptr;
				prev = nullptr;
			}

			const UserDataType& getData() const {return data;}
			UserDataType& getData() {return data;}
			void setData(const UserDataType& _data) {data = _data;}
			void setNext(Node* _next) { next = _next;}
			Node* getNext() const { return next;}
			void setPrev(Node* _prev) { prev = _prev;}
			Node* getPrev() const { return prev;}
		private:
			Node* next;
			Node* prev;
			UserDataType data;
		};


		ListNode* __allocate_new_node(const UserDataType& data) const {
			//PrintF;
			void* ptr = Allocator::allocate(sizeof(ListNode));
			ListNode* newNode = Allocator::construct(ptr,data);			
			return newNode;
		}

		void __insert_node_front(ListNode* newNode) {
			__insert_node(head,newNode,INSERT_BEFORE);
		}

		void __insert_node_back(ListNode* newNode) {
			__insert_node(tail,newNode,INSERT_AFTER);
		}

		void __insert_node(ListNode* pos,ListNode* newNode,bool front) {
			if(pos == nullptr) {
				head = newNode;
				tail = newNode;
				ListSize++;
				return;
			}
			
			ListSize++;

			ListNode* leftToPos = pos->getPrev();
			ListNode* rightToPos = pos->getNext();

			if(front) {
				__link(leftToPos,newNode);
				__link(newNode,pos);
				if(head == pos) head = newNode;
				return;
			}

			__link(pos,newNode);
			__link(newNode,rightToPos);
			if(tail == pos) tail = newNode;
			return;
		}

		void __erase_node(ListNode* pos) {
			ListNode* leftToPos = pos->getPrev();
			ListNode* rightToPos = pos->getNext();
			__link(leftToPos,rightToPos);
			if(head == pos) head = rightToPos;
			if(tail == pos) tail = leftToPos;
			Allocator::destruct(pos);
			Allocator::deallocate(pos);
			ListSize--;
		}

		void __link(ListNode * L,ListNode* R) const {
			if(L != nullptr) L->setNext(R);
			if(R != nullptr) R->setPrev(L);	
		}


		ListNode* head;
		ListNode* tail;
		unsigned int ListSize;
	};


}