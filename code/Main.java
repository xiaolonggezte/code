import java.util.ArrayList;
import java.util.List;
public class Main {
    public static void main(String []args) {
        List<String> list = new ArrayList<String>();
		list.add("a");
		list.add("a");
		list.add("b");
		list.add("a");
		list.add("a");
		
		System.out.print("remove前集合数据：");
		for (int i = 0; i < list.size(); i++) {
			System.out.print(list.get(i)+"，");
		}
		
		//删除集合中值为“1”的数据
		for (int i = 0; i < list.size(); i++) {
			if ("a".equals(list.get(i))) {
                list.remove(i);
                i --;
			}
		}
		
		System.out.println("");
		System.out.print("remove后集合数据：");
		for (int i = 0; i < list.size(); i++) {
			System.out.print(list.get(i)+"，");
		}

    }
}


