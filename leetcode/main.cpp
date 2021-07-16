#include "List.hpp"

class Message {
public:
	Message(int val = 0):x(val) {}
	int getX() const {
		return x;
	}
	void setX(int _x) {
		x = _x;
	}

	friend std::ostream& operator<<(std::ostream& os, const Message& msg);

private:
	int x;
};

std::ostream& operator<<(std::ostream& os, const Message& msg) {
    os << std::to_string(msg.getX());
    return os;
}

using namespace lib;

template<typename Container>
void Print(const Container& cont) {
	typename Container::Iterator iter = cont.Begin();
	while(iter) {
		trace(*iter);
		iter++;
	}
}

int main() {

	List<Message> list;
	list.Push_back(Message(1212));
	list.Push_back(Message(12));
	// list.Push_front(Message(3232));
	// list.Push_front(Message(78));

	// trace(list.Back());
	// trace(list.Front());
	
	List<Message>::Iterator iter = list.Begin();

	iter++;

	iter = list.Insert(iter,Message(56));
	iter = list.Insert(iter,Message(56));
	iter = list.Insert(iter,Message(56));
	
	// trace(*iter);
	
	Print<List<Message>>(list);

	// trace(list.Empty());
	iter = list.Begin();
	iter = list.Erase(iter);
	iter = list.Erase(iter);
	iter = list.Erase(iter);
	iter = list.Erase(iter);
	iter = list.Insert(iter,Message(1000));
	iter = list.Insert(iter,Message(1000));
	iter = list.Insert(iter,Message(1000));
	iter = list.Insert(iter,Message(1000));
	iter = list.Insert(iter,Message(1000));
	iter = list.Erase(iter);
	iter = list.Erase(iter);
	iter = list.Erase(iter);

	Print<List<Message>>(list);

	trace(list.Size());

	list.Clear();

	Print<List<Message>>(list);

}