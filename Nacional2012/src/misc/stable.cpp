function stableMatching
{
    Initialize all m in M and w in W to free

    while(exists a free man m who still has 
    a woman w to propose to)
    {
       w = m s highest ranked such woman who 
           he has not proposed to yet

       if(w is free)
         (m, w) become engaged

       else
       {
         some pair (m_prime, w) already exists

         if(w prefers m to m_prime)
         {
           (m, w) become engaged
           m_prime becomes free
         }	
         else
           (m_prime, w) remain engaged
      }
   }
}
