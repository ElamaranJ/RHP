import java.util.*;
public class bom_mad {
    public static void main(String []args){
        Scanner sc=new Scanner(System.in);
        int R=sc.nextInt();
        int C=sc.nextInt();
        int k=sc.nextInt();
        char arr[][]=new char[R][C];
        boolean visited[][]=new boolean[R][C];
        boolean br[]=new boolean[R];
        boolean bc[]=new boolean[C];
        for(int i=0;i<R;i++){
            String s=sc.nextLine();
            for(int j=0;j<C;j++){
                char c=s.charAt(j);
                arr[i][j]=c;
                if(c=='#'){
                    br[i]=true;
                    bc[j]=true;
                }
            }
        }
        Queue<int[]> q=new ArrayDeque<>();
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(!br[i] && !bc[j]){
                    q.add(new int[]{i,j});
                    visited[i][j]=true;
                }
            }
        }
        int ans=0;
        final int diff[]={0,1,0,-1,0};
        while(!q.isEmpty() && k-->0){
            int qsize=q.size();
            ans+=qsize;
            for(int s=0;s<qsize;s++){
                int cell[]=q.poll();
                for(int i=0;i<4;i++){
                    int ar=cell[0]+diff[i],ac=cell[1]+diff[i+1];
                    if(ar>=0 && ar<R && ac>=0 && ac<C && !visited[ar][ac] && arr[ar][ac]=='.'){
                        q.add(new int[]{ar,ac});
                        visited[ar][ac]=true;
                    }
                }
            }
        }
        System.out.println(ans);
        sc.close();
    }
}
