// package codes;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.StringTokenizer;

class SpaceshipTravel {

    static class Graph {
        int V;
        LinkedList<Integer>[] adjList;
        
        Graph(int V) {
            this.V = V;
            adjList = new LinkedList[V];

            for (int i = 0; i < V; i++) {
                adjList[i] = new LinkedList<>();
            }
        }
    }

    public static void addEdge(Graph graph, int src, int dest) {
        graph.adjList[src].add(dest);
        graph.adjList[dest].add(src);
    }
  
    public static void traverseDFS(Graph graph, int src, int vertex, ArrayList<Boolean> visited, ArrayList<ArrayList<Integer>> pairList, int parent, int itr) {
        int visitedCount = 0;
        for (int i = 0; i < vertex; i++) {
            if (visited.get(i) == true) visitedCount += 1;
        }

        // If all nodes visited
        if (visitedCount == vertex) return;

        // Mark this as visited
        visited.set(src, true);
        
        //Used in backtracking -- stores path
        pairList.add(new ArrayList<>(Arrays.asList(parent, src)));

        System.out.print(src + " ");

        LinkedList<Integer> adjListVertex = graph.adjList[src];

        // traverse in adjacency vertex if they are not visited
        for (int adjVertex: adjListVertex) {
            if (visited.get(adjVertex) == false) {
                traverseDFS(graph, adjVertex, vertex, visited, pairList, src, itr + 1);
            }
        }

        // if there is no vertex left to go
        // then go back to path where you came from
        // here pairList comes in use
        // format of pairlist [PARENT, CURRENT_VERTEX] 
        for (int p = 0; p < pairList.size(); p++) {
            ArrayList<Integer> back = pairList.get(p);
            if (back.get(1) == src) {
                traverseDFS(graph, back.get(0), vertex, visited, pairList, src, itr + 1);
            }
        }
    }


    public static void dfs(Graph graph,int vertex) {
        ArrayList<Boolean> visited = new ArrayList<>(vertex);
        ArrayList<ArrayList<Integer>> pairList = new ArrayList<>();  
        for (int i = 0; i < vertex; i++) {
            visited.add(i, false);
        }

        traverseDFS(graph, 0, vertex, visited, pairList, -1, 0);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        

        int vertex = Integer.parseInt(br.readLine());
        int edges = Integer.parseInt(br.readLine());
        Graph graph = new Graph(vertex);
        while (edges-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int src = Integer.parseInt(st.nextToken());
            int dest = Integer.parseInt(st.nextToken());
            addEdge(graph, src, dest);
            st.nextToken();
            // System.out.println("From " + src + " to " + dest);
        }

        // printGraph(graph);
        dfs(graph, vertex);
    }
}

