import java.util.Optional;

public interface LRU_Cache{
    boolean put(CacheElement cacheElement);
    Optional<CacheElement> get(CacheElement cacheElement);
    int size();
    boolean isEmpty();
    void clear();
    void printCache();
}
