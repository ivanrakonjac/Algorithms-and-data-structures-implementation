public class LRU_Test {

    public static void main(String args[]){

        LRU lru = new LRU(3);

        lru.put(new CacheElement(1));
        lru.printCache();

        lru.put(new CacheElement(2));
        lru.printCache();

        lru.put(new CacheElement(3));
        lru.printCache();

        lru.put(new CacheElement(4));
        lru.printCache();

        lru.put(new CacheElement(5));
        lru.printCache();

        lru.put(new CacheElement(3));
        lru.printCache();

        lru.put(new CacheElement(4));
        lru.printCache();

        lru.get(new CacheElement(1));
        lru.printCache();
    }

}
