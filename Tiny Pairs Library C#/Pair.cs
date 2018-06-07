using System;

class Pair<K, V>
{
    private K first { get; }
    private V second { get; }

    public Pair(K first, V second)
    {
        this.first = first;
        this.second = second;
    }

    public K getKey()
    {
        return first;
    }

    public V getValue()
    {
        return second;
    }

    public K getLeft()
    {
        return first;
    }

    public V getRight()
    {
        return second;
    }

    public bool equals(Object o)
    {
        return Equals(o);
    }

    public Object hashCode()
    {
        return GetHashCode();
    }

    public String toString()
    {
        return ToString();
    }

    public Pair<V,K> reverse()
    {
        return new Pair<V,K>(second, first);
    }
}