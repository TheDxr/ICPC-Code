public class Solution {
    public string ReverseWords(string s) {
        var words = s.Split(' ', StringSplitOptions.RemoveEmptyEntries);
        var result = "";
        for (int i = words.Length - 1; i >= 0 ; --i)
        {
            result += words[i];
            if (i != 0)
            {
                result += " ";
            }
        }

        return result;
    }
}