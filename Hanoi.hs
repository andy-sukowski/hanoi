module Main (main) where

import System.IO

move :: Int -> Char -> Char -> Char -> [(Int, Char, Char)]
move 0 _ _ _ = []
move n a c b = move (n - 1) a b c ++ [(n, a, c)] ++ move (n - 1) b c a

pretty :: (Int, Char, Char) -> IO () 
pretty (n, a, c) = do
    putStrLn $ show n ++ ": " ++ [a] ++ " → " ++ [c]

main :: IO ()
main = do
    putStr "Number of disks: "
    hFlush stdout
    input <- getLine
    let n = read input :: Int 
    mapM_ pretty $ move n 'a' 'c' 'b'
