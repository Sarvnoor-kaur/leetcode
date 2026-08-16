class Solution {
    public String mergeAlternately(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();

        String merge = "";

        for (int i = 0; i < Math.min(m, n); i++) {
            merge += word1.charAt(i);
            merge += word2.charAt(i);
        }

        if (m >= n) {
            merge += word1.substring(n);
        } else {
            merge += word2.substring(m);
        }

        return merge;
    }
}