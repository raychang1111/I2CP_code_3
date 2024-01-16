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
        cout<<1<<"->"<<i+1<<" 的最短路徑花費"<<distance[i]<<endl;
        cout<<"path: ";
        print_path(i,prev_node);
        cout<<endl;
    }
}
void Dijkstra_s(int n,vector<EDGE> &edge){          //  求出 1號點 -> n號點的最短路徑
    vector<vector<pair<int,int>>> link(n);          //  i號節點的所有{子節點,與子節點權重}
    for(int i=0;i<edge.size();i++)                  //  建立相鄰串列 
        link[edge[i].a-1].push_back({edge[i].b-1,edge[i].w});
    vector<int> prev_node(n);                       
    for(int i=0;i<n;i++)                            
        prev_node[i]=i;
    vector<int> run(n,false);                       //  紀錄是否走過
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> heap;   //找最小
    vector<int> distance(n,(int)1e9);               //  紀錄所有的點 到 點1 的距離 
    distance[0]=0;                                  //  初始點1 距離為0
    heap.push({0,distance[0]});                     //  從起點出發
    while(!heap.empty()){
        int curr_node=heap.top().first;
        heap.pop();
        if(run[curr_node])                          // 確保每個點最多只被走過一遍
            continue; 
        run[curr_node]=true;
        for(int i=0;i<link[curr_node].size();i++){  // 窮舉此點所有連到的點
            if(!run[link[curr_node][i].first]){
                int temp=link[curr_node][i].first;
                if(distance[temp]>distance[curr_node]+link[curr_node][i].second){   // 鬆弛
                    distance[temp]=distance[curr_node]+link[curr_node][i].second;   
                    prev_node[temp]=curr_node;                                      
                    heap.push({temp,distance[temp]});       // 如果有更新距離，則丟進 heap繼續找最小
                } 
            }
        }
    }
    print(prev_node,distance);                      //  輸出所有對1的最短路徑
}
void Bellman_Ford(int n,vector<EDGE> &edge){
    vector<int> distance(n,(int)1e9);               //  紀錄所有的點 到 點1 的距離
    vector<int> prev_node(n);                       //  記錄路徑
    for(int i=0;i<n;i++)
        prev_node[i]=i;
    distance[0]=0;                                  //  初始點1 距離為0
    for(int i=0;i<n-1;i++){                         //  鬆弛 N-1
        for(int j=0;j<edge.size();j++){             //  邊集合瓊舉 鬆弛
            if(distance[edge[j].b-1]>distance[edge[j].a-1]+edge[j].w){  
                distance[edge[j].b-1]=distance[edge[j].a-1]+edge[j].w;
                prev_node[edge[j].b-1]=edge[j].a-1;
            }
        }
    }
    print(prev_node,distance);                      //輸出所有對1的最短路徑
}
int main(){                                       //有向圖
    int n1=6;            //有n個點  點按1 ~ n編號 
    vector<EDGE> edge1={{1,3,9},{3,6,2},{2,4,15},{3,4,11},{6,5,9},{1,6,14},{1,2,7},{2,3,10},{4,5,6},    //邊集合
                        {3,1,9},{6,3,2},{4,2,15},{4,3,11},{5,6,9},{6,1,14},{2,1,7},{3,2,10},{5,4,6}};   
    int n2=5;
    vector<EDGE> edge2={{1,2,2},{2,4,2},{1,3,5},{3,4,-2},{4,5,1}};                                      //負環測資
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