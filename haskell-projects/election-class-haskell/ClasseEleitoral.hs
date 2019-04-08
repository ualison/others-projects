module Main (main) where

import System.IO (stdout, hSetBuffering, BufferMode(NoBuffering))

main :: IO ()
main = do hSetBuffering stdout NoBuffering
          putStrLn "::PROGRAMA - CLASSE ELEITORAL::"
          putStr "Digite uma idade: "
          s1  <- getLine
          putStrLn "A SITUACAO DO ELEITOR E A SEGUINTE: "
          putStrLn(show (verificaEleitor (read s1)))


verificaEleitor :: Int -> String
verificaEleitor n = if n < 16
                    then "Ainda nao e eleitor."
                    else if n >= 16 && n < 18 || n >= 65
                         then "Eleitor com voto facultativo."
                         else "Eleitor com voto obrigatorio."
