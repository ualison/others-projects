--01

inteiro :: Int -> String
inteiro x
  | x == 1 = "Um"
  | x == 2 = "Dois"
  | x == 3 = "Tres"
  | x == 4 = "Quatro"
  | x == 5 = "Cinco"
  | otherwise = "O valor nao esta no intervalo"

inteiro2 :: Int -> String
inteiro2 x = if x == 1 then "Um" else if x == 2 then "Dois" else if x == 3 then "Tres" else if x == 4 then "Quatro" else if x == 5 then "Cinco" else "O valor nao esta no intervalo."


--02

parimpar :: Int -> String
parimpar x
  | mod x 2 == 0 = "Par"
  | otherwise = "Impar"


parimpar2 :: Int -> String
parimpar2 x = if mod x 2 == 0
             then "Par"
             else "Impar"

--03

conversor :: Double -> Double
conversor t = c
          where c = (t-32)*5/9

--04

salario :: Double -> Double
salario x
  | x > 1000 && x <= 2000 = aux5
  | x > 2000 && x <= 3000 = aux3
  | otherwise = x
  where
   aux5 = x * 0.5;
   aux3 = x * 0.3

salario2 :: Double -> Double
salario2 x = let aux5 = x * 0.5;
                 aux3 = x * 0.3
             in if x > 1000 && x <= 2000
                then aux5
                else if x > 2000 && x <= 3000
                then aux3
                else x

--05

triangulo :: Double -> Double -> Double -> Bool
triangulo a b c
  | a == b && a == c = True
  | otherwise = False

--06

divisivel :: Int -> Bool
divisivel x
  | mod x 3 == 0 && mod x 7 == 0 = True
  | otherwise = False

--07
mediatres :: Double -> Double -> Double -> Int
mediatres a b c
  | a > media && b < media && c < media || b > media && a < media && c < media || c > media && a < media && b < media = 1
  | a > media && b > media && c < media || b > media && a > media && c < media || c > media && a > media && b < media = 2
  | a > media && b > media && c > media || b > media && a > media && c > media || c > media && a > media && b > media = 3
  | otherwise = 0
  where
    media = (a+b+c)/3

--08
soma :: Integer -> Integer
soma n
  | n == 0 = 0
  | otherwise = n + soma(n-1)

somacauda :: Integer -> Integer
somacauda x = somaAux x 0

somaAux :: Integer -> Integer -> Integer
somaAux a c
  | a == 0 = c
  | otherwise = somaAux (a-1) (c+a)

--09

produto1 :: Integer -> Integer -> Integer
produto1 m n
  | m == n = n*m
  | otherwise = produto1 m (n-1) * n

produto :: Integer -> Integer -> Integer
produto m n = produtoAux m n 1

produtoAux :: Integer -> Integer -> Integer -> Integer
produtoAux a b ac
  | a == b = ac*a
  | otherwise = produtoAux a (b-1) (ac*b)

--10

potencia :: Integer -> Integer -> Integer
potencia x y = potenciaAux x y 1

potenciaAux :: Integer -> Integer -> Integer-> Integer
potenciaAux a b ac
  | b == 0 = ac
  | otherwise = potenciaAux a (b-1) (ac*a)
