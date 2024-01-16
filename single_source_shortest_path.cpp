#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define node_a frist
#define node_b second
#define node frist
#define dis second
using namespace std;
class EDGE{
public:
    int a,b,w;
    EDGE(int i=0,int j=0,int k=0):a(i),b(j),w(k){}
};
class cmp{
public:
    bool operator()(pair<int,int> &a,pair<int,int> &b){
        return a.dis>b.dis;
    }
};
void print_path(int i,vector<int> &prev_node){
    if(prev_node[i]==i)
        cout<<i+1;
    else{
        print_path(prev_node[i],prev_node);
        cout<<"->"<<i+1;
    }
}
void print(vector<int> &prev_node,vector<int> &distance){
    for(int i=0;i<distance.size();i++){
        cout<<1<<"->"<<i+1<<" ���̵u���|��O"<<distance[i]<<endl;
        cout<<"path: ";
        print_path(i,prev_node);
        cout<<endl;
    }
}
void Dijkstra_s(int n,vector<EDGE> &edge){          //  �D�X 1���I -> n���I���̵u���|
    vector<vector<pair<int,int>>> link(n);          //  i���`�I���Ҧ�{�l�`�I,�P�l�`�I�v��}
    for(int i=0;i<edge.size();i++)                  //  �إ߬۾F��C 
        link[edge[i].a-1].push_back({edge[i].b-1,edge[i].w});
    vector<int> prev_node(n);                       
    for(int i=0;i<n;i++)                            
        prev_node[i]=i;
    vector<int> run(n,false);                       //  �����O�_���L
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> heap;   //��̤p
    vector<int> distance(n,(int)1e9);               //  �����Ҧ����I �� �I1 ���Z�� 
    distance[0]=0;                                  //  ��l�I1 �Z����0
    heap.push({0,distance[0]});                     //  �q�_�I�X�o
    while(!heap.empty()){
        int curr_node=heap.top().first;
        heap.pop();
        if(run[curr_node])                          // �T�O�C���I�̦h�u�Q���L�@�M
            continue; 
        run[curr_node]=true;
        for(int i=0;i<link[curr_node].size();i++){  // �a�|���I�Ҧ��s�쪺�I
            if(!run[link[curr_node][i].first]){
                int temp=link[curr_node][i].first;
                if(distance[temp]>distance[curr_node]+link[curr_node][i].second){   // �P��
                    distance[temp]=distance[curr_node]+link[curr_node][i].second;   
                    prev_node[temp]=curr_node;                                      
                    heap.push({temp,distance[temp]});       // �p�G����s�Z���A�h��i heap�~���̤p
                } 
            }
        }
    }
    print(prev_node,distance);                      //  ��X�Ҧ���1���̵u���|
}
void Bellman_Ford(int n,vector<EDGE> &edge){
    vector<int> distance(n,(int)1e9);               //  �����Ҧ����I �� �I1 ���Z��
    vector<int> prev_node(n);                       //  �O�����|
    for(int i=0;i<n;i++)
        prev_node[i]=i;
    distance[0]=0;                                  //  ��l�I1 �Z����0
    for(int i=0;i<n-1;i++){                         //  �P�� N-1
        for(int j=0;j<edge.size();j++){             //  �䶰�Xã�| �P��
            if(distance[edge[j].b-1]>distance[edge[j].a-1]+edge[j].w){  
                distance[edge[j].b-1]=distance[edge[j].a-1]+edge[j].w;
                prev_node[edge[j].b-1]=edge[j].a-1;
            }
        }
    }
    print(prev_node,distance);                      //��X�Ҧ���1���̵u���|
}
int main(){                                       //���V��
    int n1=6;            //��n���I  �I��1 ~ n�s�� 
    vector<EDGE> edge1={{1,3,9},{3,6,2},{2,4,15},{3,4,11},{6,5,9},{1,6,14},{1,2,7},{2,3,10},{4,5,6},    //�䶰�X
                        {3,1,9},{6,3,2},{4,2,15},{4,3,11},{5,6,9},{6,1,14},{2,1,7},{3,2,10},{5,4,6}};   
    int n2=5;
    vector<EDGE> edge2={{1,2,2},{2,4,2},{1,3,5},{3,4,-2},{4,5,1}};                                      //�t������
    cout<<"-------------Dijkstra_s---------------"<<endl;
    Dijkstra_s(n1,edge1);
    cout<<"-------------Dijkstra_s---------------"<<endl;
    Dijkstra_s(n2,edge2);
    cout<<"-------------Bellman_Ford-------------"<<endl;
    Bellman_Ford(n1,edge1);
    cout<<"-------------Bellman_Ford-------------"<<endl;
    Bellman_Ford(n2,edge2);
    return 0;
}