#include <iostream>
#include "BST.h"

using namespace std;

int main()
{
    BST<int> o;
    char choice;
    while(true)
    {
        cout << endl;
        cout<<"\n\t\t*********************************   Menu   ***************************************"<<endl;
        cout<<"\t\t*                                                                                  *";
        cout<<"\n\t\t*          1- To Insert a value into BST.                                        *";
        cout<<"\n\t\t*          2- To Print in Pre-order form.                                        *";
        cout<<"\n\t\t*          3- To Print in In-order form.                                         *";
        cout<<"\n\t\t*          4- To Print in Post-order form.                                       *";
        cout<<"\n\t\t*          5- To Delete a value from BST                                         *";
        cout<<"\n\t\t*          6- To Plot the tree.                                                  *";
        cout<<"\n\t\t*          7- To Search for an item in the BST.                                  *";
        cout<<"\n\t\t*          8- To Find the number of nodes in the BST.                            *";
        cout<<"\n\t\t*          9- To terminate the program.                                          *";

        cout << endl;
        cin >> choice;
        switch(choice)
        {

            case '1':
            {
                string valAsString;
                cout << "Enter values for tree and if you finish , hit q" << endl;
                while(cin >> valAsString)
                {
                    if(valAsString == "Q" || valAsString == "q")
                        break;
                    int val = stoi(valAsString);
                    o.insert(val);
                }
            }
                break;

            case '2':
            {
                o.preOrder();
                cout << "\n";
            }
                break;

            case '3':
            {
                o.inOrder();
            }
                break;

            case '4':
            {
                o.postOrder();
            }
                break;

            case '5':
            {
                int dVal;
                cout << "Enter the value to be deleted.\n";
                cin >> dVal;
                o.deleteNode(dVal);
            }
                break;

            case '6':
            {
                o.plot();
            }
                break;

            case '7':
            {
                int item;
                cout << "Enter an item to check if its in tree or not: \n";
                cin >> item;
                if(o.search(item))
                    cout << item << " exists in the tree.";
                else
                    cout << item << " doesn't exist in the tree.";
            }
                break;

            case '8':
            {
                cout << o.getNumberOfNodes() << endl;
            }
                break;

            case '9':
            {
                cout << "Thanks for using the program :)" << endl;
                exit(0);
            }
                break;
            default:
            {
                cout << "Error! , invalid input :(" << endl;
            }
                break;
        }
    }
    return 0;
}
