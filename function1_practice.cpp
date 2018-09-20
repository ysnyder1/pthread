#include <iostream>
#include <pthread.h>
#include <string>
using namespace std;

/* user inputs 5 numbers to be stored in an array. 
    Then user inputs a string.
    Thread is created.
    Main thread sorts int array by min value. 
    Child thread parses user input into an array of words using regex
    */
int numberArray[5];
int size = sizeof(numberArray)/sizeof(numberArray[0]);
    
    //pthread function min sort
    void* sortArray(void* args){
        
        int* array = (int*) args;
        for(int a=0; a<size-1; ++a){
            for(int b=a+1; b<size; ++b){
                if(array[a] > array[b]){
                    int holder = array[a];
                    array[a] = array[b];
                    array[b]= holder;
                    cout<< holder << " swapped with " << array[a] << ", now: " << array[a] << " --- " << array[b] << endl;
                }
            }
            for(int i=0; i<size; ++i){
            cout << array[i] << " ";
        }
            cout << "moving to a: " << a+1 << "\n" << endl;
        }
        
        for(int i=0; i<size; ++i){
            cout << array[i] << " ";
        }
    }
    
int main() {
    cout << "Enter five numbers to be stored in array" << endl;
    
    //takes user number input
    for(int i=0; i < size; ++i){
        cin >> numberArray[i];
    }
    
    //take user string
    string str;
    cout << "Input a sentence" << endl;
    cin >> str;
    
    //create a thread to execute the function to sort the numberArray
    int rc;
    pthread_t id;
    rc = pthread_create(&id, NULL, sortArray, (void*) &numberArray);
    
    //alternatively pthread_join(id, NULL) would cause the main thread to wait for child thread to finish executing before continuing
    cout << "hey i'm main thread not waiting to execute" << endl;
    
    pthread_join(id,NULL);
    cout << "okay, i'm main thread and waited for child to finish" << endl;
    //make sure main thread waits for child thread to terminate before exiting the program
    pthread_exit(0);
}