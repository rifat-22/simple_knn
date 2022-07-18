#include<bits/stdc++.h>
using namespace std;

vector<int> distance(vector<int>a, vector<int>b, vector<int>t)
{
    vector<int>d;
    int dis=0;

    //euclidian distance
    for (int i = 0; i < a.size(); i++)
    {
        dis = (a[i]-t[0])*(a[i]-t[0]) + (b[i]-t[1])*(b[i]-t[1]);
        d.push_back(dis);    
    }
    return d;
}

int initialize_k(vector<int>a)
{
    int n = a.size();
    int k = sqrt(n);

    if(k < 3)
        k = 3;

    if(k > 3)
    {
        if(k % 2 == 0)
            k = k + 1;
    }
    return k;
}

string mostFrequent(vector<string>arr) 
{ 
    map<string, int> m; 
  
    // count occurrences of every string
    for (int i = 0; i < arr.size(); i++)
    {
      map<string, int>::iterator it = m.find(arr[i]);

      if (it == m.end())
        m.insert(pair<string, int>(arr[i], 1));

      else
        m[arr[i]] += 1;
     }

    // find the max
    map<string, int>::iterator it = m.begin();
    for (auto it2 = m.begin(); it2 != m.end(); ++it2)
    {
      if (it2 -> second > it -> second)
      it = it2;
    }

    return it->first;
} 

string knn_Classify(vector<int>a, vector<int>b, vector<string>c, vector<int>t)
{
    vector<int>d;   
    vector<int>tmp;
    vector<string>label;
    vector<int>p;

    int k = initialize_k(a);

    d = distance(a,b,t);   
    //cloning distance vector
    tmp = d;
    //ranking the distance vector from low to high
    sort(tmp.begin(),tmp.end());
    //only keeping the first k elements
    tmp.resize(k);

    //finding indices of k shortest distances from original distance vector
    for (int i = 0; i < d.size(); i++)
    {
        for (int j = 0; j < k; j++)
        {
            if(d[i] == tmp[j])
            {
                p.push_back(i);
                break;
            }
        }
    }

    // creating a vector of k shortest distances
    for (int i = 0; i < k; i++)
    {
        label.push_back(c[p[i]]);
    }
    
    //applying majority and return the result
    return mostFrequent(label);
}

int main()
{
    ifstream file("input.txt");
	string str,s1;
    int s;
    //x1 and x2 (2D) input 
    vector<int>x1;      
    vector<int>x2;      
    vector<int>x;       //test data
    vector<string>y;    //classification 

    //file input 
    while (getline(file, str))
	{
		istringstream ss(str);
		ss >> s;
        x1.push_back(s);
		ss >> s;
        x2.push_back(s);
		ss >> s1;
        y.push_back(s1);
	}
    //test data
    x.push_back(3);
    x.push_back(7);

    s1 = knn_Classify(x1,x2,y,x);
    cout<<s1;
}