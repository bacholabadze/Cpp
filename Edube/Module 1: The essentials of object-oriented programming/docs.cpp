// What does any object have?

// 1) an object has a name that uniquely identifies it within its home namespace (although there may be some anonymous objects, too)
// 2) an object has a set of individual properties that make it original, unique or outstanding (although there is the possibility that some objects may have no properties at all)
// 3) an object has a set of abilities to perform specific activities that can change the object itself or some of the other objects


// "Max is a large cat who sleeps all day"

// Object name = Max
// Home class = Cat
// Property = Size (large)
// Activity = Sleep (all day)


// ----------------------------------------- Stack aka LIFO----------------------------------

// A stack is structure developed to store data. Imagine a stack of coins. You can't put a coin anywhere else but on the top of the stack
// You can't geta coin off the stack from anywhere other than the stack's top. If you want to get the coin on the bottom, you have to remove all coins that are sitting on top of it

// The alternative name for a stack is LIFO (Last In - First Out)

// A stack is an object to two elementary operations conventionally named "push"(when a new element is placed on top)
// and "pop" (when an existing elemenent is taken away from the top)


int stack[100]; // We assume that there’ll be no more than 100 values on the stack at the same time
// We also assume that the element at index 0 is at the bottom of the stack.


// Stack pointer - But the array isn’t enough to implement a stack. We need a few additional details. For example, we need a variable that can be responsible for storing a number of elements currently stored on the stack. This variable is generally called a “stack pointer”, or SP for short.
int SP = 0;


// Push
// We’re now ready to define a function that places a value onto the stack. Here is what we’ve supposed:

// the name for the function is "push"
// the function gets one parameter of type int (this is the value to be placed onto the stack)
// the function returns nothing (self-explanatory, right?)
// the function places the parameter value into the first free element in the vector and increments the SP
void push(int value){
    stack[SP++] = value;
}


// Pop
// Now it’s time for the function to take a value off the stack. This is how we imagine it:
//
// the name for the function is "pop" (we don’t want to discover America again)
// the function doesn’t have any parameters
// the function returns the value taken from the stack
// the function reads the value from the stack’s top and decrements SP
int pop(void){
    return stack[--SP];
}

// The function doesn’t check if there’s any element on the stack (we prefer to refrain from comments).


// [!] Pros and Cons
// Our procedural stack is ready. Of course, it has some weaknesses and the implementation could be improved in many ways, but the general idea is fine and we can use our stack if needed.
// But...

// ----- Disadvantages : The more often we use it, the more disadvantages we discover. Let’s have a look at some of them.
// two essential variables (stack and SP) are completely vulnerable; anyone can modify them in an uncontrollable way, destroying the stack; this doesn’t mean that it’s done maliciously – on the contrary, it may happen as a result of carelessness;

// imagine that you’ve accidentally written something like this:
SP = 100;
// The functioning of the stack will be completely disorganized.

// it may happen that one day you need more than one stack; be prepared to work hard – you’ll have to create another vector for the stack’s storage, another stack pointer for a new vector, probably more push and pop functions too;

// it may also happen that you need not only push and pop functions, but also some other things; you can implement them but try to imagine what’ll happen when you have dozens of separately implemented stacks

// we’ve used the int stack so far, but you may want to use the stacks defined for other types: floats, strings or even arrays and structures; what’ll happen then?


// ----- Advantages : The objective approach provides solutions for each of these problems. Let’s name them first.

// 1) the ability to protect selected values against unauthorized access is called encapsulation; the encapsulated values can be neither accessed nor modified if you want to use them exclusively
// 2) when you have a class implementing all the needed stack behaviours, you can produce as many stacks as you want; you don’t need to copy or replicate any part of the code
// 3) the ability to enrich the stack with new functions (inheritance); you can create a new class or subclass which inherits all the existing traits from the superclass and adds some new ones
// 4) you can create a template which is a generalized, parameterized class, ready to materialize itself in many different incarnations; its code can adapt to varying requirements and, for example, create stacks ready to work with other types of data



// --------------------------------------------------- Stack OOP ----------------------------------------------------------------
//Let’s write a brand new stack implementation from scratch. We’ll use the objective approach, guiding you step by step into the world of object programming.


// Now it’s time for two functions that implement push and pop operations. The C++ language assumes that a function of this kind (being a class activity) may be described in two different way:

// 1) inside the class, when the class body contains a full implementation of the method
// 2) outside the class, when the body contains only the function header; the function body is placed outside the class

class Stack {
private:  // To be honest, you don’t need to use the private keyword at this point. It’s assumed as default when no other option is implicitly specified.
    int stackstore[100];
    int SP;
public:
    /* We have to add another function to our class. It’s a very specialized function invoked implicitly every time a new stack is created. We call it a [!] “constructor” because it’s responsible for the proper construction of each new object of the class. */
    Stack(void) { SP = 0 }

    void push(int value);
    int pop(void){
        return stackstore[--SP];
    }
};

// The functions implementing the class’ activities and placed outside the class body need to be described in a very specific way. Their names should be qualified using the home class name and the “::” operator.
void Stack::push(int value){
    stackstore[SP++] = value;
};

// Note one important fact: both functions access the class variables without any obstacles.


/*
We want the new class to be able to evaluate a sum of all the elements currently stored on the stack. Weird, right?

We don’t want to modify the previously defined stack. It’s good enough as it is, and we don’t want to change it in any way. We want a new stack with new capabilities.*/

// In other words, we want to construct a subclass of the Stack class.

class AddingStack:Stack{
    // The class doesn’t define any new component yet, but that doesn’t mean that it’s empty. It derives all the components defined by its superclass – the name of the superclass is written after the colon directly after the new class name.

    // [!] Any object of the AddingStack class can do everything that each Stack class’ object does.

    // 1. We want the push function not only to push the value onto the stack, but also to add the value to the sum variable
    // 2. We want the pop function not only to pop the value off the stack, but also to subtract the value from the sum variable

private:
    int sum;
public:
    ADdingStack(void) { sum = 0 }
    void push(int value);
    int pop(void);
};

// We’ll start with the implementation of the push function. This is what we expect from it:

// 1. to add the value to the sum variable
// 2. to push the value onto the stack

void AddingStack:push(int value){
    sum += value;
    Stack::push(value); // the only thing we need to do is to use it, but we must clearly indicate the class containing the function to avoid confusing it with any other function of the same name.
}

int AddingStack:pop(void){
    int val = Stack::pop();
    sum -= val;
    return val;
}

int AddingStack::getSum(void){
    return sum;
}


// ----------------------------------------------------- Completed AddingStack Code -------------------------------------

class AddingStack:Stack(void){
private:
    int sum;
public:
    AddingStack(void);
    void push(int value);
    int pop(void);
    int getSum(void);
};

// Yes, it’s about the initial value of the sum variable. It should be zeroed when the object is created. We can do this in the constructor – it’s not hard. We know already how to write constructors,
// but there’s one thing that should be emphasized.
// Note the phrase “: Stack()”. It’s a request to invoke the superclass constructor before the current constructor starts its work.
AddingStack::AddingStack(void) : Stack(){
    sum = 0;
}

AddingStack::push(int value) {
    sum += value;
    Stack::push(value);
}

AddingStack::pop(void){
    int val = Stack::pop();
    sum -= val;
    return val;
}

AddingStack::getSum(void){
    return sum;
}
// ---------------------------------------------------------------------------------------------------------------------------
