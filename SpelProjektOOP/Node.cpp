#include "Node.h"



template<typename T>
Node<T>::Node()
{
	prev_ = nullptr;
	next_ = nullptr;
}

template<typename T>
Node<T>::Node(T const& data) :
	Node()
{
	this->data = data;
}

template<typename T>
Node<T>::~Node()
{}



template<typename T>
void Node<T>::prepend(Node<T>* node)
{
	if (node != nullptr)
	{
		node->next = this;
		node->prev = prev_;
		if (node->prev != nullptr)
			node->prev->next = node;
	}

	prev_ = node;
}

template<typename T>
void Node<T>::append(Node<T>* node, bool ignorePrev)
{
	if (node != nullptr)
	{
		if (!ignorePrev)
			node->prev_ = this;
		node->next_ = next_;
		if (node->next_ != nullptr)
			node->next_->prev_ = node;
	}

	next_ = node;
}

template<typename T>
void Node<T>::remove()
{
	if (prev_ != nullptr)
		prev_->next_ = next_;

	if (next_ != nullptr)
		next_->prev_ = prev_;

	prev_ = nullptr;
	next_ = nullptr;
}



template<typename T>
Node<T>* Node<T>::getPrev() const
{
	return prev_;
}

template<typename T>
Node<T>* Node<T>::getNext() const
{
	return next_;
}