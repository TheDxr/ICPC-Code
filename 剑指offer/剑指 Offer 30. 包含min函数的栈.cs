public class MinStack
{
    private Stack<int> minStack;
    private Stack<int> stack;
    public MinStack() {
        minStack = new Stack<int>();
        stack = new Stack<int>();
    }
    
    public void Push(int x) {
        stack.Push(x);
        if (minStack.Count == 0 || minStack.Peek() >= x)
        {
            minStack.Push(x);
        }
    }
    
    public void Pop()
    {
        var top = stack.Pop();
        if ( top == minStack.Peek()) minStack.Pop();
    }
    
    public int Top()
    {
        return stack.Peek();
    }
    
    public int Min()
    {
        return minStack.Peek();
    }
}