// Name: Ivan Tlaseca
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 10

#include "PQ_Heap.h"
#include "heap.h"
#include <iostream>
#include <ctime>
#include <ctype.h>
#include <string>

using namespace std;

void printMenu();

void convert(string& s){
    for(int i = 0; i < s.length(); i++){
        s[i] = tolower(s[i]);
    }
}

void intPQ(){
    
    priority_queue_heap<int> intPQHeap; //Are we supposed to be making Heap objects in this program instead? Needed for case 7..
    
    int choice;
    do{
        cout<<endl;
        printMenu();
        cin >> choice;
        switch(choice){
            case 1:
                //Enqueue element   (Working)
                int enQint;
                if(intPQHeap.is_full()){
                    cout<<"Heap is full."<<endl;
                }else{
                    cout<<"Enter element to enqueue"<<endl;
                    cin >> enQint;
                    intPQHeap.enqueue(enQint);
                }
                break;
            case 2:                                                     //Dequeue element (Working)
                if(intPQHeap.is_empty()){
                    cout<<"No elements to dequeue"<<endl;
                    break;
                }else{
                    int x = intPQHeap.dequeue();
                    cout << "Dequeued: " << x << endl;
                }
                break;
            case 3:      
                //Check is_full (Working)
                if(intPQHeap.is_full()){
                    cout<<"The heap is full."<<endl;
                }else{
                    cout<<"The heap is not full."<<endl;
                }
                break;
            case 4:
                //Check is_empty    (Working)
                if(intPQHeap.is_empty()){
                    cout<<"The heap is empty."<<endl;
                }else{
                    cout<<"The heap is not empty."<<endl;
                }
                break;
            case 5:
               cout<<intPQHeap.size()<<endl; 
                //Print size (Working)
                break;
            case 6:
                //Display front element (Working)
                if(intPQHeap.is_empty()){
                    cout<<"The heap is empty."<<endl;
                }else{
                    cout<<"Front element: "<<intPQHeap.front()<<endl;
                }
                break;
            case 7:
                cout<<endl;    // (Working)
                intPQHeap.check_PQ_heap();
                cout<<endl;
                break;
            case 8:
                cout<<"Program ended."<<endl;
                break;
            default:
                cout<<"Invalid Command."<<endl;
                break;
            
        }
    }while(choice != 8);
    
}
void stringPQ(){
    priority_queue_heap<string> stringPQ;
    int choice;
    string enQString;
    do{
        cout<<endl;
        printMenu();
        cin >> choice;
        switch(choice){
            case 1:                                                 //Enqueue element
                if(stringPQ.is_full()){
                    cout<<"Heap is full."<<endl;
                }else{
                    cout<<"Enter element to enqueue"<<endl;
                    cin >> enQString;
                    stringPQ.enqueue(enQString);
                }
                break;
            case 2:                                                     //Dequeue element
                if(stringPQ.is_empty()){
                    cout<<"No elements to dequeue"<<endl;
                    break;
                }else{
                    string x = stringPQ.dequeue();
                    cout << "Dequeued: " << x << endl;
                }
                break;
            case 3:
                //Check is_full
                if(stringPQ.is_full()){
                    cout<<"The heap is full."<<endl;
                }else{
                    cout<<"The heap is not full."<<endl;
                }
                break;
            case 4:
                //Check is_empty
                if(stringPQ.is_empty()){
                    cout<<"The heap is empty."<<endl;
                }else{
                    cout<<"The heap is not empty."<<endl;
                }
                break;
            case 5:
                //Print size
                cout<<stringPQ.size()<<endl;
                break;
            case 6:
                //Display front element
                if(stringPQ.is_empty()){
                    cout<<"The heap is empty."<<endl;
                }else{
                    
                    cout<<"Front element: "<<stringPQ.front()<<endl;
                }
                break;
            case 7:
                //Print queue elements
                cout<<endl;
                stringPQ.check_PQ_heap();
                cout<<endl;
                break;
            case 8:
                cout<<"Program ended."<<endl;
                break;
            default:
                cout<<"Invalid Command."<<endl;
                break;
        }
     }while(choice != 8);
}

int main(){
    
    string queueType;
    bool qEntered = false; 
    priority_queue_heap<int> we; 
    while(qEntered == false){   //Queue Type Selection
        cout<<"0.Enter a Queue Type (int or string)"<<endl;
        cin >> queueType;
        convert(queueType);
        if(queueType == "string" || queueType == "int"){
            qEntered = true;
        }else{
            qEntered = false;
        }
    }
    if(queueType == "string"){
        stringPQ();
    }else{
        intPQ();
    }
}


void printMenu(){
    cout<<"1. Enqueue Element"<<endl;
    cout<<"2. Dequeue Element"<<endl;
    cout<<"3. Check is_full"<<endl;
    cout<<"4. Check is_empty"<<endl;
    cout<<"5. Print size"<<endl;
    cout<<"6. Display front element"<<endl;
    cout<<"7. Print queue elements"<<endl;
    cout<<"8. Quit program"<<endl;
}