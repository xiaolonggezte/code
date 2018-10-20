/**
    单例模式的几种实现
 */
public class Mains {
    public static void main(String[] args) {

    }
}
// 饱汉式
class SingleTon2 {
    private SingleTon2() {
        
    }
    private static SingleTon2 instance = SingleTon2();
    public static SingleTon2 getInstance() {
        return instance;
    }
}

// 饿汉式
class SingleTon3 {
    private SingleTon3() {
        
    }
    private static SingleTon3 instance;
    public static SingleTon3 getInstance() {
        if(instance == null) {
            instance = SingleTon3();
        }
        return instance;
    }
}
// 双重判定
class SingleTon {
    private SingleTon() {

    }
    private static SingleTon instance;
    public static SingleTon getInstance() {
        if(instance == null) {
            synchorized (instance){
                if(instance == null) {
                    instance = new SingleTon();
                }
            }
        }
        return instance;
    }
}


// 内部静态类

class SingleTon4 {
    private SingleTon4() {

    }
    private static class SingleTonFactory {
        public static SingleTon4 instance = new SingleTon4(); 
    }
    public static SingleTon4 getInstance() {
        return SingleTonFactory.instance;
    }
}



