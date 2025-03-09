#include <iostream> 
using namespace std; 
int main() { 
int num = 10; 
int* ptr = &num; 
// Print initial values 
cout << "Value of num: " << num << endl; 
cout << "Address of num: " << &num << endl;
cout << "Value of ptr: " << ptr << endl; 
cout << "Value pointed by ptr: " << *ptr << endl; 
// Modify value using pointer 
*ptr = 20; 
// Print modified values 
cout << "\nModified value of num: " << num << endl; 
cout << "Modified value of ptr: " << ptr << endl; 
cout << "Modified value pointed by ptr: " << *ptr << endl; 
return 0;
}
