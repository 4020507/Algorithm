class Solution {
    public int lengthOfLastWord(String s) {
        int length = s.length();
        if(length == 0 || s.equals(" "))
            return 0;
        
        String[] divide = s.split(" ");
        
        int i = 0;
        while(true)
        {
            try
            {
                s = divide[i];
                i++;
            }
            catch(Exception e)
            {
                i--;
                break;
            }
        }
        
        if(i != -1)
            return divide[i].length();
        else
            return 0;
        
    }
}
