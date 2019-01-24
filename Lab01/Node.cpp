Node::Node(int num)
{
  m_number = num;
  next = nullptr;
}

int Node::getNum() const
{
  return m_number;
}

void Node::setNum(int num)
{
  m_number = num;
}

Node* Node::getNext() const
{
  return next;
}

void Node::setNext(Node* nextNode)
{
  next = nextNode;
}
