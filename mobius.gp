n=10000
pp=0
nn=0
istrue=0
array_mobius=vector(n)
for (i=1, n, array_mobius[i]=moebius(i);)

\\ Fonctions de selection de sous listes (inutiles ici)
/*
inferior(l, n)=
{
    return (select(x->setsearch(l, x)<n, l));
}

superior(l, n)=
{
    return (select(x->setsearch(l, x)>n, l));
}
*/

/* listage selon la valeur de moebius (non utilisée)
initialization()=
{
    for (i=1, n,
        listput(list_pn, i);
        if(moebius(i)==1,
            listput(list_p, i);
        );
        if(moebius(i)==-1,
            listput(list_n, i);
        );
    );
}*/

positive(a, b)=
{   
    if (a==b,
        pp=(moebius(a)==1);
        return (pp+1);
    );
    if (moebius(b)==1,
        pp=pp+1;
    );
    return (pp);
}

negative(a, b)=
{
    if (a==b,
        nn=(moebius(a)==-1);
        return (nn+1);
    );
    if (moebius(b)==-1,
        nn=nn+1;
    );
    return (nn);
}

mob()={
    array_m=listcreate();
    cnt=0;
    mem=vector(2);
    mem[1]=0;
    mem[2]=0;
    for (i=1, n,
        if (array_mobius[i]==1,
            mem[1]+=100;
            mem[2]-=99;
        );
        if (array_mobius[i]==-1,
            mem[1]-=99;
            mem[2]+=100;
        );
        listput(array_m, [mem[1], mem[2]]);
        if (mem[1]>=0 & mem[2]>=0,
            cnt+=1;
        );
    );
    print ("done");

    /* il faut essayer de trier array_m de maniere optimale*/
    /*listsort(array_m);
    print (array_m);*/

    for (i=2, n,
        if (array_mobius[i-1]==0,
            previous-=1;
            cnt+=previous;
        ,
            previous=0;
            if (array_mobius[i-1]==1, 
                for (j=i, n,
                    array_m[j][1]-=100;
                    array_m[j][2]+=99;
                    if (array_m[j][1]>=0 & array_m[j][2]>=0,
                        previous+=1;
                    );
                );
            ,
                for (j=i, n,
                    array_m[j][1]+=99;
                    array_m[j][2]-=100;
                    if (array_m[j][1]>=0 & array_m[j][2]>=0,
                        previous+=1;
                    );
                );
            );
            cnt+=previous;
        );
    );
  
    print (cnt);
}

/*
mobius(k)=
{
    n=k;
    pp=0;
    nn=0;
    istrue=0;
    cnt=0;
    for(a=1, n,
        if (a>1 & moebius(a-1)==0, 
            \\ Il faut penser à enlever 1 pour le cas ou a==b
            previous-=1;
            cnt+=previous;
        ,
            previous=0;
            for (b=a, n-10,
                if (b>a & moebius(b)==0,
                    previous+=istrue;
                ,
                    neg=negative(a, b);
                    pos=positive(a, b);
                    if (100*neg>=99*pos & 99*neg<=100*pos,
                        previous+=1;
                        istrue=1;
                    ,
                        istrue=0;
                    );
                );
                if (a==1 & istrue==1, 
                    print (b);
                );
            );
            cnt+=previous+10;
        );
    );

    print(cnt);
}*/
