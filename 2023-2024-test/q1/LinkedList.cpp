#include <iomanip>

#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList(void)
{
    head = NULL;
    tail = NULL;
}

LinkedList::~LinkedList(void)
{
    destroyList();
}

void LinkedList::appendNode(string passengerName, string SeatNo, string DeparturePort, string DestinationPort, string boardingGate, string Flighttime, string Flightdate, string FlightNo)
{

    Node *newNode = new Node(passengerName, SeatNo, DeparturePort, DestinationPort, boardingGate, Flighttime, Flightdate, FlightNo);

    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void LinkedList::displayNodes()
{

    Node *current = head;

    while (current != NULL)
    {

        // just play around with the values passed into setw function until it matches the format shown in the output
        // \n - for specifying a new line within a string

        cout << "--------------------------------------------------------------------------------------------------" << endl;
        cout << setw(55) << "ARIK AIRLINE" << endl;
        cout << setw(56) << "BOARDING PASS\n"
             << endl;
        cout << "PASSENGER NAME:" << current->passengerName << setw(19) << "DATE:" << current->Flightdate << endl;
        cout << "SOURCE PORT:" << current->DeparturePort << setw(44) << "DESTINATION PORT:" << current->DestinationPort << endl;
        cout << "BOARDING GATE:" << current->boardingGate << setw(35) << "SEAT NO:" << current->SeatNo << endl;
        cout << "FLIGHT TIME:" << current->Flighttime << setw(35) << "FLIGHT NO:" << current->FlightNo << "\n"
             << endl;
        cout << setw(55) << "Have a safe trip" << endl;
        cout << "--------------------------------------------------------------------------------------------------\n"
             << endl;

        current = current->next;
    }
}

void LinkedList::destroyList()
{

    Node *current = tail;

    while (current != NULL)
    {
        Node *temp = current;
        current = current->prev;
        delete temp;
    }

    head = NULL;
    tail = NULL;
}
