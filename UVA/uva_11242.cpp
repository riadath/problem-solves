    #include <bits/stdc++.h>
    using namespace std;
    int main()
    {
        int f,r;
        while(scanf("%d",&f) && f && scanf("%d",&r))
        {
            float fr[f],bk[r];
            for(int i = 0;i < f;i++){
                cin>>fr[i];
            }
            for(int i = 0;i < r;i++){
                cin>>bk[i];
            }
            vector <float> sp;
            for(int i = 0;i < r;i++){
                for(int j = 0;j < f;j++){
                    sp.push_back(bk[i]/fr[j]);
                }
            }


            sort(sp.begin(),sp.end());

            /*for(int i = 0;i < sp.size();i++)cout<<sp[i]<<" ";
            cout<<endl;*/
            vector <float> sp2;
            for(int i = 0;i < sp.size()-1;i++){
                sp2.push_back(sp[i+1] / sp[i]);
            }

           /* for(int i = 0;i < sp2.size();i++)cout<<sp2[i]<<" ";
            cout<<endl;*/

            float ans = *max_element(sp2.begin(),sp2.end());
            printf("%0.02f\n",ans);
        }
        return 0;
    }

























