public class StringInJava {
    public static void main(String[] args) {
        String str = "Hello";   // memory for 'str' gets stored in string pool(a special area in heap)
        String str2 = new String("Hello");   // memory for 'str2' gets stored in heap, not in string pool

        if(str == str2) System.out.println("They are equal");
        else System.out.println("They are not equal");
        // Output for above code with be "They are not equal", because '==' operator compares values based on
        // references, not the contents of the strings. In this case, str and str2 refer to different objects
        // in memory, even though they contain the same value "Hello". Therefore, the == operator will return false.
        // The equals() method in Java compares the actual contents of the strings, not just their memory references.
        // Even though str and str2 are different objects in memory, their contents are the same ("Hello"). Therefore,
        // when you use the equals() method, it returns true, indicating that the strings are equal.
        if(str.equals(str2)) System.out.println("They are equal");
        else System.out.println("They are not equal");

        System.out.println(str.charAt(0));   // H
        System.out.println(str.substring(1, 3));   // el
        System.out.println(str.substring(2));   // llo

        System.out.println(str.contains("el"));   // true
        System.out.println(str.contains("ee"));   // false


        String s1 = "Bhai";
        String s2 = "bhai";

        System.out.println(s1.equals(s2));   // false
        System.out.println(s1.equalsIgnoreCase(s2));   // true

        System.out.println(s1.toUpperCase());   // BHAI
        System.out.println(s1.toLowerCase());   // bhai


        String ss = "   abc d   ";
        System.out.println(ss);   //    abc d
        System.out.println(ss.trim());   // abc d

        String sentence = "This is my home, its so beautiful";
        String[] words = sentence.split(" ");
        for(String i: words) {
            System.out.print(i + "$");   // This$is$my$home,$its$so$beautiful$
        }
        System.out.println();

        System.out.println(sentence.startsWith("This"));   // true
        System.out.println(sentence.endsWith("this"));   // false

        int num = 10;
        String s = String.valueOf(num);   // returns a string(10)
        System.out.println(num + 1);   // 11
        System.out.println(s + 1);   // 101

        String word = "Rajasthan";
        System.out.println(word.replace('a', 'b'));   // Rbjbsthbn

        char[] ch = word.toCharArray();
        for(char i: ch) {
            System.out.print(i + " ");   // R a j a s t h a n
        }
        System.out.println();

        String abc = " ";
        String abcd = "Hi";
        System.out.println(abc.isEmpty());   // false
        System.out.println(abc.isBlank());   // true
        System.out.println(abcd.isEmpty());   // false
        System.out.println(abcd.isBlank());   // false
    }
}
