#include <iostream>
#include <list>
#include <vector>

using namespace std;

int currentGroup = 1;

class nodo
{
public:
    nodo(string name)
    {
        this->name = name;
    }
    string name;
    list<nodo>adj;
    int group;
};

bool isGroupZero(vector<nodo>& graph)
{
    for (vector<nodo>::iterator iterate = graph.begin();iterate != graph.end();iterate++)
    {
        if(iterate->group == 0)
            return true;
    }
    return false;
}
void setGroup(nodo &n)
{
    n.group = currentGroup;
}

void searchValid(vector<nodo>& graph)
{
    for(unsigned int i = 0;i < graph.size();i++)
    {
        if( graph[i].group == 0)
        {
            bool flag = true;

            for (vector<nodo>::iterator iterate = graph.begin();iterate != graph.end();iterate++)
            {
                if(iterate->group == currentGroup)
                flag = false;
            }

            if(!flag)
                setGroup(graph[i]);
        }
    }
}

int main()
{
    vector<nodo> group;
    int i = 0;

    while(isGroupZero(group))
    {
        nodo current = group[i++];
        setGroup(current);
        searchValid(group);
        currentGroup++;
    }
    for (vector<nodo>::iterator iterate = group.begin();iterate != group.end();iterate++)
    {
        cout<<iterate->name<<" "<<iterate->group<<"/n"<<endl;
    }

}
