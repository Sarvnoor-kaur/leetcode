class Solution {
    public int numberOfSpecialChars(String word) {

        HashMap<Character, Integer> mp = new HashMap<>();

        for (int i = 0; i < word.length(); i++) {

            char ch = word.charAt(i);

            if (Character.isUpperCase(ch) && !mp.containsKey(ch)) {

                mp.put(ch, i);

            } else if (Character.isLowerCase(ch)) {

                mp.put(ch, i);
            }
        }

        Set<Character> s1 = new HashSet<>();

        for (int i = 0; i < word.length(); i++) {

            char ch = word.charAt(i);

            if (Character.isLowerCase(ch)) {
                s1.add(ch);
            }
        }

        int count = 0;

        for (char c : s1) {

            char upper = Character.toUpperCase(c);

            if (mp.containsKey(upper) && mp.get(c) < mp.get(upper)) {
                count++;
            }
        }

        return count;
    }
}