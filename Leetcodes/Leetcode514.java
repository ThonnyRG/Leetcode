class Solution {
    public double maxProbability(int n, int[][] edges, double[] succProb, int start, int end) {
        
        List<double []>[] graph = new ArrayList[n];
        for(int i=0;i<n;i++){
            graph[i] = new ArrayList<>();
        }
        for(int i=0;i<edges.length;i++){
            graph[edges[i][0]].add(new double[]{edges[i][1],succProb[i]});
            graph[edges[i][1]].add(new double[]{edges[i][0],succProb[i]});
        }
        boolean []vis = new boolean[n];
        PriorityQueue<double[]> pq = new PriorityQueue<>((a,b)->Double.compare(b[1],a[1]));
        pq.add(new double[]{start,1});

        while(pq.size()!=0){

            double [] temp = pq.poll();
            if(temp[0] == end){
                return temp[1];
            }
            if(vis[(int)temp[0]]){
                continue;
            }
            vis[(int)temp[0]] = true;
            for(double []nbr : graph[(int)temp[0]]){
                pq.add(new double[]{nbr[0],temp[1]*nbr[1]});
            }
        }
        return 0.0;
    }
}