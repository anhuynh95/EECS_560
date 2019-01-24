LinkedList::LinkedList()
{
  head = nullptr;
  length = 0;
}

LinkedList::~LinkedList()
{
  Node* temp = head;
  while(temp != nullptr)
  {
    temp = temp->getNext();
    delete head;
    head = temp;
  }
}

bool LinkedList::IsEmpty() const
{
  if(length == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void LinkedList::Insert(int num)
{
  Node* newNode = new Node(num);
  if(IsEmpty() == true)
  {
    head = newNode;
    length++;
  }
  else
  {
    Node* temp = head;
    while(temp->getNext() != nullptr)
    {
      temp = temp->getNext();
    }
    temp->setNext(newNode);
    length++;
  }
}

void LinkedList::Delete(int num)
{
  Node* previous = head;
  Node* current = head;
  if(IsEmpty() == true)
  {
    std::cout<<"Your list has no element to delete.";
  }
  else if(current->getNum() == num)
  {
    current = current->getNext();
    delete previous;
    std::cout<<"Delete was successful.";
    length--;
  }
  else
  {
    current = current->getNext();
    while (current != nullptr)
    {
      if(current->getNum() == num)
      {
        break;
      }
      else
      {
        previous = current;
        current = current->getNext();
      }
    }
    if(current == nullptr)
    {
      std::cout<<"Delete failed. Number was not found in the list.";
    }
    else
    {
      previous->setNext(current->getNext());
      delete current;
      std::cout<<"Delete was successful.";
      length--;
    }
  }
}

int LinkedList::Smallest() const
{
  Node* temp = head;
  int min = 0;
  while(temp->getNext() != nullptr)
  {
    if(min > temp->getNum())
    {
      min = temp->getNum();
    }
    temp = temp->getNext();
  }
  return min;
}

int LinkedList::Largest() const
{
  Node* temp = head;
  int max = 0;
  while(temp->getNext() != nullptr)
  {
    if(max < temp->getNum())
    {
      max = temp->getNum();
    }
    temp = temp->getNext();
  }
  return max;
}

double LinkedList::Average() const
{
  Node* temp = head;
  int sum = 0;
  double ave = 0;
  while(temp->getNext() != nullptr)
  {
    sum = sum + temp->getNum();
    temp = temp->getNext();
  }
  ave = sum/length;
  return ave;
}

void LinkedList::sort()
{
  Node* current = head;
  int temp = 0;
  for(int i=1; i<length; i++)
  {
    while(current->getNext() != nullptr)
    {
      if(current->getNum() > current->getNext()->getNum())
      {
        temp = current->getNum();
        current->setNum(current->getNext()->getNum());
        current->getNext()->setNum(temp);
        current = current->getNext();
      }
      else
      {
        current = current->getNext();
      }
    }
    current = head;
  }
}

void LinkedList::Print()
{
  Node* current = head;
  std::cout<<"List: ";
  while(current->getNext() != nullptr)
  {
    std::cout<<current->getNum() + " ";
    current = current->getNext();
  }
  std::cout<<"\n";
}
