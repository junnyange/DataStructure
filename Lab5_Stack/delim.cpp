//--------------------------------------------------------------------
//
//  Laboratory 5 (In-lab 3 shell)                          delim.cs
//
//  Program validates delimiter pairing.
//
//--------------------------------------------------------------------

#include <string>
#include "stacklnk.cpp"

//--------------------------------------------------------------------
//
//  Function prototype

bool delimitersOk ( const string &expression );

//--------------------------------------------------------------------

int main(void)
{
    string inputLine;            // Input line
    char ch;                     // Holding pen for input chars

    cout << "This program checks for properly matched delimiters."
         << endl;

    while( cin )
    {
        cout << "Enter delimited expression (<EOF> to quit) : "
             << endl;

        // Read in one line
        inputLine = "";
        cin.get(ch);
        while( cin && ch != '\n' )
        {
            inputLine = inputLine + ch;
            cin.get(ch);
        }
    
        if( ! cin )              // Reached EOF: stop processing
            break;

        if ( delimitersOk (inputLine) )
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
    }

    return 0;
}


bool delimitersOk(const string& expression)
{
    Stack<char> testStack;
    char c;
   
    for (int i = 0; i < expression.length(); i++)
    {
        switch (expression[i])
        {
        case '(': case '{': case '[':
            testStack.push(expression[i]);
            break;

        case ')':
            if (testStack.isEmpty() == true)
                return false;
            c = testStack.pop();
            if (c != '(')
                return false;
            break;

        case '}':
            if (testStack.isEmpty() == true)
                return false;
            c = testStack.pop();
            if (c != '{')
                return false;
            break;

        case ']':
            if (testStack.isEmpty() == true)
                return false;
            c = testStack.pop();
            if (c != '[')
                return false;
            break;

        default:
            break;
        }
    }
    if (testStack.isEmpty() == true)
        return true;
    else 
        return false;
}