import java.util.*;

public class LRU implements LRU_Cache{

    private final int maxCacheCapacity;
    private final Map<Integer, CacheElement> hashMap;
    private final List<CacheElement> queue;
    private int tempCacheSize;

    public LRU(int maxCacheCapacity) {
        this.maxCacheCapacity = maxCacheCapacity;
        this.hashMap = Collections.synchronizedMap(new HashMap<>());
        this.queue = Collections.synchronizedList(new LinkedList<>());
        this.tempCacheSize = 0;
    }

    @Override
    public boolean put(CacheElement cacheElement) {

        if(hashMap.containsKey(cacheElement.getValue())){
            queue.remove(cacheElement);
            queue.add(0, cacheElement);
            return true;
        }

        if(tempCacheSize == maxCacheCapacity){
            queue.remove(queue.size()-1);
            tempCacheSize--;
        }

        queue.add(0, cacheElement);
        tempCacheSize++;
        return true;
    }

    @Override
    public Optional<CacheElement> get(CacheElement cacheElement) {
        CacheElement result = hashMap.get(cacheElement.getValue());
        return result == null ? Optional.empty() : Optional.of(result);
    }

    @Override
    public int size() {
        return tempCacheSize;
    }

    @Override
    public boolean isEmpty() {
        return tempCacheSize == 0;
    }

    @Override
    public void clear() {
        queue.clear();
    }

    @Override
    public void printCache() {
        for (CacheElement cacheElem:queue) System.out.print(cacheElem + " | ");
        System.out.println("");
    }

    public static void main(String args[]){
        System.out.println("LRU");
    }

}
