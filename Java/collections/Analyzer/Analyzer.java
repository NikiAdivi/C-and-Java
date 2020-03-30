class Analyzer
{
  LinkedHashSet<String> elements=new LinkedHashSet<String>();
  // TreeSet<String> sorted_elements=new TreeSet<String>();
  Map<String,Integer> m=new HashMap<String,Integer>();

  Analyzer(Arraylist<String> arr)
  {
    for(String s: arr)
    {
      elements.add(s);
    }
  }

  public ArrayList<String> sort_lexicographic()
  {
    Collections.sort(elements,new Comparator<String>(){
    public int compare(String a,String b)
    {
      return a-b;
    }
  });
}

  public ArrayList<String> sort_size()
  {
    sort_lexicographic();
    Collections.sort(elements,new Comparator<String>(){
    public int compare(String a,String b)
    {
      return a.length-b.length;
    }
  });
  }

  public count_no()
  {
    for(Iterator<String> it=elements.iterator();it.hasNext())
    {
      m.put(it.next().charAt(0),1)
    }
  }

  /*if(myMap.containsKey(key)) {
      myMap.replace(key, value);
  } else {
      myMap.put(key, value);
  }*/
}
