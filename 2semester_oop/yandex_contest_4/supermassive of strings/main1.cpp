//private int y;
//public double Cost;
//
//public ImplicitTreap Left;
//public ImplicitTreap Right;
//public int Size = 1;
//
//private ImplicitTreap(int y, double cost, ImplicitTreap left = null, ImplicitTreap right = null)
//{
//    this.y = y;
//    this.Cost = cost;
//    this.Left = left;
//    this.Right = right;
//}
//
//public static int SizeOf(ImplicitTreap treap)
//{
//return treap == null ? 0 : treap.Size;
//}
//
//public void Recalc()
//{
//    Size = SizeOf(Left) + SizeOf(Right) + 1;
//}
//
//// теперь после заготовки - собственно Split
//
//public void Split(int x, out ImplicitTreap L, out ImplicitTreap R)
//{
//    ImplicitTreap newTree = null;
//    int curIndex = SizeOf(Left) + 1;
//
//    if (curIndex <= x)
//    {
//        if (Right == null)
//            R = null;
//        else
//            Right.Split(x - curIndex, out newTree, out R);
//        L = new ImplicitTreap(y, Cost, Left, newTree);
//        L.Recalc();
//    }
//    else
//    {
//        if (Left == null)
//            L = null;
//        else
//            Left.Split(x, out L, out newTree);
//        R = new ImplicitTreap(y, Cost, newTree, Right);
//        R.Recalc();
//    }
//}