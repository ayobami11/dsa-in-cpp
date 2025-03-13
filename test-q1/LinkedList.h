#pragma once

#include <iostream>
#include <string>

using namespace std;

struct Node
{
    // data
    string passengerName;
    string SeatNo;
    string DeparturePort;
    string DestinationPort;
    string boardingGate;
    string Flighttime;
    string Flightdate;
    string FlightNo;
    // pointers
    Node *prev;
    Node *next;

    Node(string passengerName, string SeatNo, string DeparturePort, string DestinationPort, string boardingGate, string Flighttime, string Flightdate, string FlightNo)
    {
        this->passengerName = passengerName;
        this->SeatNo = SeatNo;
        this->DeparturePort = DeparturePort;
        this->DestinationPort = DestinationPort;
        this->boardingGate = boardingGate;
        this->Flighttime = Flighttime;
        this->Flightdate = Flightdate;
        this->FlightNo = FlightNo;

        prev = NULL;
        next = NULL;
    }
};

class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList(void);
    ~LinkedList(void);

    void appendNode(string passengerName, string SeatNo, string DeparturePort, string DestinationPort, string boardingGate, string Flighttime, string Flightdate, string FlightNo);
    void displayNodes();
    void destroyList();
};
