void prims(int start){
        int reach[nv];
        int unreach[nv];
        int result[nv][nv];
        
        for(int i = 0;i <nv;i++){
            for(int j  = 0;j<nv;j++){
            result[i][j]  = 0;
            }
        }
        
        
        for(int i  = 0;i<nv;i++){
            reach[i] = 0;
            unreach[i] = 1;
            
        }
        
        int edge = 0;
        int weight = 0;
        reach[start] = 1;
        unreach[start] = 0;
        cout<<"Path"<<"\t"<<"cost"<<endl;
        while(edge < nv-1){
            int s = 100000;
            int flag = 0;
            int a = 0,b = 0;
            for(int i = 0;i<nv;i++){
            if(reach[i] == 1){
                for(int j = 0;j<nv;j++){
                    if(unreach[j] == 1){
                        if(s>adjmat[i][j] && adjmat[i][j] != 0){
                            flag =1;
                            s = adjmat[i][j];
                            a = i;b=j;
                            
                        }
                    }
                }
            }
        }
        
        if(flag == 1){
            weight+=s;
            reach[b] = 1;
            unreach[b] =0;
            edge++;
            result[a][b] = s;
        }
        
        }
        
        for(int i = 0;i<nv;i++){
            
            for(int j = 0;j<nv;j++){
                if(result[i][j]!=0)
                cout<<i<<"-"<<j<<"\t"<<result[i][j]<<endl;
            }
        }
        
        cout<<"D=================================================D"<<endl;
    }  