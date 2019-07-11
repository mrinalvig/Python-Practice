#include <iostream>
#include <string>
#include <stack>
using namespace std;

int factorial(int, stack<int>);
int fibonacci(int, int, stack<int>);
void print(stack<int>);

int main()
{
    bool loop = true;
    stack <int> call;
    
    cout<<"Please select a positive integer" << endl;
    int num;
    cin >> num;
    
    cout << "Would you like to implement a Factorial[1] or Fibonacci[2] method?" << endl;
    int decision;
    cin >> decision;
    
    while(loop == true)
    {
        if (decision == 1)
        {
            cout << "\nThe Factorial of " << num << " = " << factorial(num, call) << endl;
            loop = false;
        }
        else if (decision == 2)
        {
            cout << "\nThe Fibonacci series at number " << num << " is: " << fibonacci(num, num, call) << endl;
            loop = false;
        }
        else
        {
            cout << "This is not an option, please try again" << endl;
            cin >> decision;
        }
    }
    

    return 0;
}

int factorial(int num, stack<int> call)
{
    call.push(num);
    print(call);
    
    int fact = 1;
    
    if (num <= 1)
    {
		print(call);
		call.pop();
        return 1;
    }
    else
    {
        fact = num * factorial(num-1, call);
		print(call);
        return fact;
    }
}

int fibonacci(int num1, int num2, stack<int> call)
{
    call.push(num1);
    
    cout << "calling f(" << call.top() << ") from f(" << num2 << ")" << endl;
    
    int result = 1;
    
    if (num1 <= 2)
    {
      return 1;
    }
    else
    {
		result = (fibonacci(num1-1, num1, call) + fibonacci(num1-2, num1, call)); 
        return result;
    }
	
    
}

void print(stack<int> call)
{
	int num = call.top();
    cout << "___________" << endl;
	
    while (call.size() > 0) 
	{
        cout << "n = " << call.top() << endl;
        call.pop();
    }
    for (int i = num; num > 0; num--) 
	{
        call.push(i);
    }
	
	/*
    while(!call.empty()) 
    { 
        cout << "num = " << call.top() << " " << endl; 
        call.pop(); 
    } 
	*/
}