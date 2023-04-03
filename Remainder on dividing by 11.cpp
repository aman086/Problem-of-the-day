int xmod11(string x)
        {
            int r=(x[0]-'0')*10+(x[1]-'0');
            for(int i=2; i<x.size(); i++){
                r=(r%11)*10+(x[i]-'0');
            }
            return r%11;
        }
