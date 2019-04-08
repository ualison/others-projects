module Main (main) where
import System.IO
import System.Environment(getArgs, getProgName)

calculaMedia :: Float -> Float -> String
calculaMedia a b
              | med < 3 = "Reprovado"
              | med >= 3 &&  med < 7 = "Exame Especial"
              | otherwise = "Aprovado"
              where
                  med = media a b

media :: Float-> Float -> Float
media x y = (x+y)/2


pegavalor1 :: String -> Float
pegavalor1 s = z
             where x = words s;
                   y = (x !! 2);
                   z = read y :: Float

pegavalor2 :: String -> Float
pegavalor2 s = z
             where x = words s;
                   y = (x !! 3);
                   z = read y :: Float

main :: IO()
main =
    do args <- getArgs
       case args of
        [entry, exit]->
         do entrada <- openFile entry ReadMode
            saida <- openFile exit WriteMode
            mainloop entrada saida
            hClose entrada
            hClose saida
            putStrLn "TERMINADO!"

mainloop entrada saida =
         do terminou <- hIsEOF entrada
            if terminou
               then return()
               else do inpStr <- hGetLine entrada
                       hPutStrLn saida (inpStr ++ "---" ++ show (media (pegavalor1 inpStr) (pegavalor2 inpStr)) ++ "----" ++ show (calculaMedia (pegavalor1 inpStr) (pegavalor2  inpStr)))
                       mainloop entrada saida
