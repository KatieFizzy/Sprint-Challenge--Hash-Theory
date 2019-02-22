#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "ex2.h"

char **reconstruct_trip(Ticket **tickets, int length)
{
  HashTable *ht = create_hash_table(16);
  char **route = malloc(length * sizeof(char *));

  /* PSUEDOCODE / LOGIC */
  //populate hashtable 
  for (int i = 0; i < length; i++) { // assign/insert source to keys, and destination to values 
  hash_table_insert(ht, tickets[i]->source, tickets[i]->destination);
  }

  // change value of NONE to 'start' and 'end'
  for (int i = 0; i < length; i++) {
    if (tickets[i]->source == "NONE") {
      tickets[i]->source = "START";
    }
    if (tickets[i]->destination == "NONE"){
      tickets[i]->destination = "END";
    }
  }

  char* current_city = tickets[0]->source; // set current city to start
 
  while(current_city != "END") { // as long as current city hasn't reached 'end', continue to loop 
    current_city = hash_table_retrieve(ht,current_city);
    for (int i = 0; i < length; i++) { // fill in route with entry for each city visited
    route[i] = hash_table_retrieve(ht,current_city); 
    } 
  }

  current_city = "END"; // set current city to end
  //append current_city to route // 

  return route;
}

void print_route(char **route, int length)
{
  for (int i = 0; i < length; i++) {
    printf("%s\n", route[i]);
  }
}



#ifndef TESTING
int main(void)
{
  // Short test
  Ticket **tickets = malloc(3 * sizeof(Ticket *));

  Ticket *ticket_1 = malloc(sizeof(Ticket));
  ticket_1->source = "START";
  ticket_1->destination = "PDX";
  tickets[0] = ticket_1;

  Ticket *ticket_2 = malloc(sizeof(Ticket));
  ticket_2->source = "PDX";
  ticket_2->destination = "DCA";
  tickets[1] = ticket_2;

  Ticket *ticket_3 = malloc(sizeof(Ticket));
  ticket_3->source = "DCA";
  ticket_3->destination = "END";
  tickets[2] = ticket_3;

  print_route(reconstruct_trip(tickets, 3), 3); // PDX, DCA, NONE

  return 0;
}
#endif


 