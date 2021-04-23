module Main (main) where

import System.IO

move :: Int -> Char -> Char -> Char -> [(Int, Char, Char)]
move 0 _ _ _ = []
move n a b c = move (n - 1) a c b ++ [(n, a, c)] ++ move (n - 1) b a c

pretty :: (Int, Char, Char) -> String
pretty (n, a, c) = show n ++ ": " ++ [a] ++ " → " ++ [c]

main :: IO ()
main = do
    putStr "Number of disks: "
    hFlush stdout
    input <- getLine
    let n = read input :: Int 
    mapM_ putStrLn $ map pretty $ move n 'a' 'b' 'c'
