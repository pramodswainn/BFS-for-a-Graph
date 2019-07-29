#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;


class graph
{
    int index;
    vector<int> *arr;

    public :
     graph(int index):index(index)
     {
         arr = new vector<int>[index];
     }

     void addedge(int x,int y);
     void BFS(int x);

};

void graph::addedge(int x,int y)
{
    arr[x].push_back(y);
}

void graph::BFS(int x)
{
    list<int>l;
    //list<int>::iterator i;
    bool *statud_arr = new bool[index];
    for(int i=0;i<index ;i++)
    {
        statud_arr[i] = false;
    }

    statud_arr[x] = true;
    l.push_back(x);

    while(!l.empty())
    {
       x = l.front();
       cout<<x<<" ";
       l.pop_front();

        for(auto i= arr[x].begin();i!= arr[x].end();i++)
       {
           if(!statud_arr[*i]){
               statud_arr[*i] = true;
               l.push_back(*i);
           }
       }
       
    }


}

int main()
{
  graph g(5);
  g.addedge(0,1);
  g.addedge(0,2);
  g.addedge(1,2);
  g.addedge(2,0);
  g.addedge(2,3);
  g.BFS(2);

    return 0;
}