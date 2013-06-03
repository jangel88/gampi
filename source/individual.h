#include <iostream>
#include <math.h>

#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include "node_info.h" 
#include "cart_space.h"




class Individual : public std::vector<nodeid> {
  private:
    double fitness;
    void swap_segment(bool mirror1, bool mirror2); 
    void cut_n_paste_segment(bool mirror); 
    void head_to_tail(bool mirror,Domain* space); 
  protected:
  public: 
    Individual(Individual* parent, bool shuffle); 
    Individual(int length, nodeid* nodeids, bool shuffle); 
    void mutate(Domain*); 
    static void crossover 
      (Individual parent1, Individual parent2, Individual* offspring1, Individual* offspring2); 
    float get_fitness(std::vector<int>* topology); 
    void show_Individual(); 
    float give_fitness();
    size_t hash(std::vector<nodeid>::iterator ,std::vector<nodeid>::iterator );
    void show_zcoors(Domain *space);
};

