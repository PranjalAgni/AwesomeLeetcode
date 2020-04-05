class Solution {
    public int findContentChildren(int[] g, int[] s) {
      Arrays.sort(g, 0, g.length);
      Arrays.sort(s, 0, s.length);  
      int gEnd = g.length - 1;
      int sEnd = s.length - 1;
      int content = 0;
      while (gEnd >= 0 && sEnd >= 0) {
          if (s[sEnd] >= g[gEnd]) {
              sEnd -= 1;
              content += 1;
              //gEnd -= 1;
          }
          gEnd -= 1;
        }
        
        return content;
    }
}