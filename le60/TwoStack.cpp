#include <bits/stdc++.h>
class TwoStack
{
  int *arr;
  int top1;
  int top2;
  int size;

public:
  // Initialize TwoStack.
  TwoStack(int s)
  {
    this->size = s;
    arr = new int[size];
    top1 = -1;
    top2 = s;
  }

  // Push in stack 1.
  void push1(int num)
  {
    top1++;
    if (top1 < size && top1 != top2)
    {
      arr[top1] = num;
    }
    else
    {
      top1--;
    }
  }

  // Push in stack 2.
  void push2(int num)
  {
    top2--;
    if (top2 >= 0 && top1 != top2)
    {
      arr[top2] = num;
    }
    else
    {
      top2++;
    }
  }

  // Pop from stack 1 and return popped element.
  int pop1()
  {
    if (top1 == -1)
    {
      return -1;
    }
    else
    {
      top1--;
      return arr[top1 + 1];
    }
  }

  // Pop from stack 2 and return popped element.
  int pop2()
  {
    if (top2 == size)
    {
      return -1;
    }
    else
    {
      top2++;
      return arr[top2 - 1];
    }
  }
};
