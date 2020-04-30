#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<stdlib.h>
using namespace std;

int the_main();

class liner_array
{
    int choice, s, arr[1], pos;
public:
    liner_array()
    {
        choice=0;
        s=0;
        pos=0;
    }
    void menu();
    void insertion();
    void display();
    void update();
    void del();
}ar;

class stack
{
    int choice, s, stk[1], pos, i, top;
public:
    stack()
    {
        choice = 0;
        s=0, top=-1;
        pos = 0;
        i=0;
    }
    void stack_menu();
    void push();
    void pop();
    void show_stack();
}st;

class queue
{
    int choice1, size, front, rear, que[1], ptr;
public:
    queue()
    {
        choice1=0, size=0, front=-1, rear=-1, ptr=0;
    }
    void q_menu();
    void simple_menu();
    void circular_menu();
    void s_enqueue();
    void s_dequeue();
    void c_enqueue();
    void c_dequeue();
    void c_display();
    void display();
}q;

void queue::q_menu()
{
    cout<<"YOU ARE IN QUEUE SECTION"<<endl;
    while(1)
    {
        cout<<endl<<"1. Simple Queue"<<endl<<"2. Circular Queue"<<endl<<"3. Previous Menu"<<endl;
        cout<<endl<<"Enter your choice: ";
        cin>>choice1;

        switch(choice1)
        {
            case 1:
                cout<<"Enter size of Queue: ";
                cin>>size;
                que[size];
                simple_menu();
            break;

            case 2:
                cout<<"Enter size of Queue: ";
                cin>>size;
                que[size];
                circular_menu();
            break;

            case 3:
            the_main();
            break;

            default:
            cout<<"Invalid choice"<<endl;
        }

    }
}

void queue::simple_menu()
{
    while (1)
    {
        cout<<endl<<"YOU ARE IN SIMPLE QUEUE SECTION"<<endl;
        cout<<"1. Enqueue"<<endl<<"2. Dequeue"<<endl<<"3. Previous Menu"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice1;

        switch(choice1)
        {
            case 1:
            s_enqueue();
            display();
            break;

            case 2:
            s_dequeue();
            display();
            break;

            case 3:
            q_menu();
            break;

            default:
            cout<<"Invalid choice"<<endl;
        }
    }
}

void queue::s_enqueue()
{
    if (rear==size-1)
        cout<<endl<<"Queue is Full"<<endl;
    else
    {
       cout<<"Enter Element: ";
        cin>>que[++rear];
    }
}

void queue::s_dequeue()
{
    if (front==rear)
        cout<<endl<<"Queue is empty"<<endl;
    else
    {
        front++;
    }
}

void queue::display()
{
    cout<<endl<<"QUEUE STATUS"<<endl;
    for (int i=front+1; i<rear+1; i++)
        cout<<que[i]<<" ";
}

void queue::circular_menu()
{
    cout<<"YOU ARE IN CIRCULER QUEUE SECTION"<<endl;
    while(1)
    {
        cout<<"1. Enqueue"<<endl<<"2. Dequeue"<<endl<<"3. Previous Menu"<<endl;
        cout<<"Enter Your Choice: ";
        cin>>choice1;

        switch(choice1)
        {
            case 1:
                c_enqueue();
                c_display();
            break;

            case 2:
                c_dequeue();
                c_display();
            break;

            case 3:
                q_menu();
            break;

            default:
            cout<<"Invalid Choice"<<endl;

        }
    }
}

void queue::c_enqueue()
{
    ++rear;
    if (rear==size-1 && front==-1 )
        cout<<"Queue is Full"<<endl;

    else if(rear==size-1 && front!=-1)
    {
        if (front!=ptr)
        {
            cout<<"Enter Element: ";
            cin>>que[ptr++];
        }
    }
    else
    {
        cout<<"Enter Element: ";
        cin>>que[rear];
    }
}

void queue::c_dequeue()
{
    if (front==rear)
        cout<<"Queue is Empty"<<endl;
    else
    {
        ++front;
        if (front==size-1 && ptr!=0)
        {
            front=0;
            front++;
        }
    }
}

void queue::c_display()
{
    cout<<endl<<"CIRCULAR QUEUE STATUS"<<endl;
    for (int i=front; i!=rear; )
    {
        if (i==size-1)
        {
            i=0;
            while(i!=rear)
            {
                cout<<que[i++]<<" ";
            }
        }
        cout<<que[++i]<<" ";
    }
    cout<<endl<<endl;
}

void stack::stack_menu()
{
    cout<<endl<<"YOU ARE IN STACK SECTION"<<endl;
    cout<<"Enter the size of Stack : ";
    cin>>s;
    stk[s];

    while(1)
    {
        cout<<endl<<"1. Push"<<endl<<"2. Pop"<<endl<<"3. Previous Menu"<<endl;
        cout<<endl<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                push();
            break;
            case 2:
                pop();
            break;
            case 3:
                the_main();
            break;

            default:
            cout<<"Invalid choice"<<endl;
        }
    }
}

void stack::push()
{
    if (top==s)
        cout<<"Stack is Full"<<endl;
    else
    {
        cout<<"Enter Element : ";
        cin>>stk[++top];
        show_stack();
    }
}

void stack::pop()
{
    if (top==-1)
        cout<<"Stack is empty"<<endl;
    else
    {
        top--;
        show_stack();
    }
}

void stack::show_stack()
{
    for (int i=top; i>=0; i--)
        cout<<stk[i]<<endl;
}

void liner_array::menu()
{
    while(1)
    {

        cout<<endl<<"1. Insertion\t"<<"2. Display\t"<<"3. Update\t"<<"4. Deletion\t"<<"5. Previous Menu"<<endl;
        cout<<endl<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
            cout<<endl<<"Enter size of array : ";
            cin>>s;
            arr[s];

            cout<<endl<<"Enter "<<s<<" elements : ";
            for (int i=0; i<s; i++)
                cin>>arr[i];
            cout<<"Insertion completed"<<endl;
            break;

            case 2:
            if (s==0)
                cout<<endl<<"No Item Inserted"<<endl;
            else
            {
                cout<<endl<<"Array Status : ";
                for (int i=0; i<s; i++)
                cout<<arr[i]<<" ";
            }
            break;

            case 3:
                if (s==0)
                cout<<endl<<"No Item Inserted"<<endl;
                else
                {
                    int val;
                    cout<<"Enter Position to update value: ";
                    cin>>pos;
                    if (pos>=0&&pos<s)
                    {
                        cout<<"Enter new value: ";
                        cin>>val;
                        arr[pos]=val;
                    }
                    else
                    cout<<"Invalid Position"<<endl;

                }
            break;

            case 4:
            if (s==0)
            cout<<endl<<"No Item Inserted"<<endl;
            else
            {
                int p;
                cout<<"Enter position to delete value: ";
                cin>>p;
                if (p>=0&&p<s)
                {
                    for (int i=p; i<s-1; i++)
                    {
                        arr[i]=arr[i+1];
                    }
                    s=s-1;
                }
                else
                cout<<"Invalid Position"<<endl;
            }
            break;

            case 5:
            the_main();
            break;

            default:
            cout<<"Invalid choice"<<endl;
        }
    }
}

int the_main()
{
    while(1)
    {
        int choice;

        cout<<setw(50)<<"DATA STRUCTURE PROGRAM"<<endl<<endl;
        cout<<"1. ARRAY"<<endl<<"2. STACK"<<endl<<"3. QUEUE"<<endl<<"4. LINKED LIST"<<endl<<"5. TREE "<<endl;
        cout<<"6. GRAPH"<<endl<<"7. SORTING"<<endl<<"8. EXIT"<<endl;
        cout<<"Enter Your Choice : ";
        cin>>choice;

        switch(choice)
        {
            case 1:
            ar.menu();
            break;

            case 2:
            st.stack_menu();
            break;

            case 3:
            q.q_menu();
            break;

            case 4:

            break;

            case 5:

            break;

            case 6:

            break;

            case 7:

            break;

            case 8:
            exit(0);
            break;

            default:
            cout<<"Invalid choice"<<endl;
        }
    }
    return 0;
}

int main()
{
    the_main();

    return 0;
}
