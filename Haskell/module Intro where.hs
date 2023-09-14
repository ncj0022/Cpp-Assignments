module Intro where
import Data.List

-- mutiple cases - one rule for each

fact 0 = 1
fact n = n * fact (n-1)

-- with the usual if-then-else
fact1 x = if x==0 then 1 else x * fact1 (x-1)

-- as a lambda expression

fact2 = \x->if x==0 then 1 else x * (fact2 (x-1))

-- some list operations

length_  [] = 0
length_ (_:xs) = 1 + (length_ xs)

-- ++ in Haskell
append [] ys = ys
append (x:xs) ys = x : (append xs ys)
 
{-
append [1,2,3] [4,5] = 1 : (append [2,3] [4,5]) =

1 : (2 : (append [3] [4,5])) =

  1 : (2 : (3 : (append [] [4,5])))
  
  1 : (2 : (3 : [4,5]))
  
-}


--member :: Eq t => t->[t]->Bool

member _ [] = False
member x (y:_) | x==y = True
member x (_:xs) = member x xs
 
take_ 0 _ = []
take_ k (x:xs) | k > 0 = x : take_ (k-1) xs
 
drop_ 0 xs = xs
drop_ k (_:xs) = drop_ (k-1) xs


-- a higher order function

map_ _ [] = []
map_ f (x:xs) = (f x) : (map_ f xs)

zipWith_ _ [] _ = []
zipWith_ _ _ [] = []
zipWith_ f (x:xs) (y:ys) = (f x y) : (zipWith_ f xs ys)

sum_ n [] = n
sum_ n (x:xs) = x + (sum_ n xs)

foldr_ _ z [] = z
foldr_ f z (x:xs) = f x (foldr_ f z xs)

prod n xs = foldr_ (*) n xs

fact3 n = prod 1 [1..n]

-- list comprehensions

-- cartesian product: as set of pairs
cprod xs ys = [(x,y)|x<-xs,y<-ys]

-- disjoint union - each element marked with a tag 0 or 1
disj_union xs ys = (cprod [0] xs) ++ (cprod [1] ys)

-- infinite lists

worm = 0 : worm

{-
worm = 0:worm = 0 : 0:worm = 0 : 0: 0: worm ....
-}

-- with recursion as usual: slow

slowfibo 0 = 1
slowfibo 1 = 1
slowfibo n | n > 1 = slowfibo (n-2) + slowfibo (n-1)
 
-- with infinite lists - fast as with a while loop in C
fibo n = (fiboFrom 1 1) !! n 
 
fiboFrom x y = x : fiboFrom y (x+y)

fibos k = take k (fiboFrom 1 1)

-- fixpoints

fact4 = fix (\f->(\x->if x==0 then 1 else x * (f (x-1))))

fix f  = f (fix f)

{- interactions

Last login: Fri Sep 27 10:31:59 on ttys001
HS$ ghci
GHCi, version 8.6.3: http://www.haskell.org/ghc/  :? for help
Prelude> :l haskellIntro
[1 of 1] Compiling Intro            ( haskellIntro.hs, interpreted )
Ok, one module loaded.
*Intro> :t length
length :: Foldable t => t a -> Int
*Intro> :t member
member :: Eq t => t -> [t] -> Bool
*Intro> :r
[1 of 1] Compiling Intro            ( haskellIntro.hs, interpreted )

Prelude> :r
[1 of 1] Compiling Intro            ( haskellIntro.hs, interpreted )
Ok, one module loaded.
*Intro> :t member
member :: Int -> [Int] -> Bool
*Intro> :r
[1 of 1] Compiling Intro            ( haskellIntro.hs, interpreted )

*Intro> :t member
member :: Eq t => t -> [t] -> Bool

*Intro> member 4 [1,2,5,7]
False
*Intro> member 4 [1,2,5,7,4]
True
*Intro> :t map
map :: (a -> b) -> [a] -> [b]
*Intro> map succ [1..5]
[2,3,4,5,6]
*Intro> map (\x->x*x) [1..5]
[1,4,9,16,25]
*Intro> (\x->x*x) 5
25

*Intro> (\x->(\y->(x+2*x))) 5 10
15
*Intro> (\x->(\y->(x+2*y))) 5 10
25
*Intro> (\y->(5+2*y)) 10
25
*Intro> (5+2*10)
25
*Intro> :t map
map :: (a -> b) -> [a] -> [b]
*Intro> :t (+)
(+) :: Num a => a -> a -> a
*Intro> :t (\x->(\y->(x+2*y)))
(\x->(\y->(x+2*y))) :: Num a => a -> a -> a
*Intro> :t map
map :: (a -> b) -> [a] -> [b]
*Intro> :t zipWith
zipWith :: (a -> b -> c) -> [a] -> [b] -> [c]
*Intro> zipWith (+) [1,2,3] [10,20,30]
[11,22,33]
*Intro> zip [1,2,3] [10,20,30]
[(1,10),(2,20),(3,30)]
*Intro> zip [1,2,3] [10,20,30,40]
[(1,10),(2,20),(3,30)]
*Intro> unzip it
([1,2,3],[10,20,30])
*Intro> :r
[1 of 1] Compiling Intro            ( haskellIntro.hs, interpreted )
Ok, one module loaded.
*Intro> zipWith_ (+) [1,2,3] [10,20,30]

<interactive>:37:1: error:
    â€¢ No instance for (Show (Integer -> Integer))
        arising from a use of â€˜printâ€™
        (maybe you haven't applied a function to enough arguments?)
    â€¢ In a stmt of an interactive GHCi command: print it
*Intro> zipWith_ (+) [1,2,3] [10,20,30]

<interactive>:38:1: error:
    â€¢ No instance for (Show (Integer -> Integer))
        arising from a use of â€˜printâ€™
        (maybe you haven't applied a function to enough arguments?)
    â€¢ In a stmt of an interactive GHCi command: print it
*Intro> 
*Intro> :r
[1 of 1] Compiling Intro            ( haskellIntro.hs, interpreted )
Ok, one module loaded.
*Intro> zipWith_ (+) [1,2,3] [10,20,30]
[11,22,33]
*Intro> :t  zipWith
zipWith :: (a -> b -> c) -> [a] -> [b] -> [c]
*Intro> :t  zipWith_
zipWith_ :: (t1 -> t2 -> a) -> [t1] -> [t2] -> [a]
*Intro> zipWith_ (+) [1,2,3] [10,20,30,40]
[11,22,33*** Exception: haskellIntro.hs:(43,1)-(44,55): Non-exhaustive patterns in function zipWith_

*Intro> zipWith (+) [1,2,3] [10,20,30,40]
[11,22,33]
*Intro> :r
[1 of 1] Compiling Intro            ( haskellIntro.hs, interpreted )
Ok, one module loaded.
*Intro> zipWith_ (+) [1,2,3] [10,20,30,40]
[11,22,33]
*Intro> zipWith (+) [1,2,3] [10,20,30,40]
[11,22,33]
*Intro> :q
Leaving GHCi.
HS$ 


-}
