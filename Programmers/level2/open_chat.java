import java.util.*;

class Solution {
    public String[] solution(String[] record) {
        
        Map<String,String> m = new HashMap<>();
        ArrayList<String> a = new ArrayList<>();
        int len = 0;

        for(String order : record)
        {
            String[] s = order.split(" ");
            StringTokenizer st = new StringTokenizer(order," ");
            String command = st.nextToken();
            if(command.equals("Enter") || command.equals("Change"))
            {
                String id = st.nextToken();
                String nick = st.nextToken();
                m.put(id,nick);
            }
            
            if(command.equals("Enter") || command.equals("Leave"))
                len++;
        }
        String[] answer = new String[len];
        len = 0;
        for(String order : record)
        {
            StringTokenizer st = new StringTokenizer(order," ");
            String command = st.nextToken();
            if(command.equals("Enter"))
            {
                String id = m.get(st.nextToken());
                answer[len] = id + "님이 들어왔습니다.";
                len++;
            }
            else if(command.equals("Leave"))
            {
                String id = m.get(st.nextToken());
                answer[len] = id + "님이 나갔습니다.";
                len++;
            }
        }
        return answer;
    }
}
