classdef population
    %This class contains the population of individuals
    
    properties
        popArray; %Array of individuals
    end
    
    methods
        
        %constructor method
        function obj = population(World) %take World as input
            for count =1:10
                Array(count) = individual(World); %create an individual            
            end
            obj.popArray = Array; %create pop array of 10 individuals
            obj = sortFitness(obj);
        end
        
        %set population
        function obj = set.popArray(obj, Value)
            %set the value of pop with a 1x10 or 1x20 vector of individuals
            checkSize = size(Value);
            if (checkSize(1) == 1) && (checkSize(2) == 10 || checkSize(2) ==20)%only update pop with 1x10 vector or 1x20 vector
                obj.popArray=Value;
            else
                error('invalid population');
            end
        end
        
        %sort population
        function [obj,averageFitness] = sortFitness(obj)
            %orders the population from best fitness to worst fitness
            
            sizeSort = size(obj.popArray); %find how many individuals in pop
            sizeSort = sizeSort(2); 
            
            %for as many individuals are in the population, create a
            %temporary array of just the fitness scores
            for index = 1:sizeSort
                tempIndividual = obj.popArray(index);
                fitnessArray(index) = tempIndividual.fitness;
            end
            
            %sort fitnessArray (B is the array sorted lowest to highest, I
            %is the array index from fitness array)
            [B,I] = sort(fitnessArray);
            averageFitness = mean(B);
            
            %use newly found I to build temp array of ordered individuals
            for index = 1:sizeSort
                fromPopIndex = I(index);
                tempArray(index) = obj.popArray(fromPopIndex);
            end
            
            obj.popArray = tempArray;
            
        end
        
        %get fittest individual
        function [path,fitness, averageFitness] = getBest(obj)
        %this function returns the path and fitness of the fittest
        %individual in the population.
        
        [obj, averageFitness] = sortFitness(obj); %sort fitness
        ind = obj.popArray(1); %get individual with best fitness
        path=ind.route; %get the route of the best individual
        fitness = ind.fitness; %get fitness of best individual
            
        end
        
        %get random individual
        function [path,fitness, averageFitness] = getRandom(obj)
        %this function returns the path and fitness of the fittest
        %individual in the population.
        
        [obj, averageFitness] = sortFitness(obj); %sort fitness
        ind = obj.popArray(randi([2 4],1)); %get individual with best fitness
        path=ind.route; %get the route of the best individual
        fitness = ind.fitness; %get fitness of best individual
            
        end
               
        %Breed population
        function obj = breedPop(obj,World)
        %this function breeds the population
            
            offSpringArray =obj.popArray; %init offspring array

            
            count=1;
            while count<6
            mummy = parent(obj.popArray);
            daddy = parent(obj.popArray);
                %while mother==father,select father again to ensure no
                %duplication
                while mummy.progenator.route == daddy.progenator.route
                    daddy = parent(obj.popArray);
                end
            
            %extract individual from parent
            mummy = mummy.progenator.route;
            daddy = daddy.progenator.route;
            
            %Perform Crossover
            [obj,child1, child2] = crossOver(obj,mummy,daddy,World);
            index1 = (2*count)-1;
            index2 = (2*count);
            offSpringArray(index1) =child1;
            offSpringArray(index2) =child2;
            count=count+1;
            end
            
            %mutate
            [obj,offSpringArray] = Mutate(obj,offSpringArray);
            
            %combine offspringarray with popArray
            obj.popArray = [obj.popArray,offSpringArray];
            for x=1:20
                y = obj.popArray(x);
                y = determineFitness(y,World);
                obj.popArray(x)=y;
            end
            
           
            obj = cullPop(obj,World);
        end
        
        %Crossover Method
        function [obj,child1, child2] = crossOver(obj,mummy,daddy,World)
        %perform crossover  
            x = size(World);
            x = x(1);
            choice = randi([floor(x/3) ceil(2*x/3)],1,1);
            child1route = mummy(1,1:choice); %first 6 of mum
            routeTemp = daddy; %temp copy of dad
            for index= 1:choice
                value=mummy(index); %get first 6 of mum
                routeTemp(routeTemp == value) = []; %remove first 6 of mum from temp dad
            end
            child1route=[child1route,routeTemp]; %child = 6 of mum plus ordered leftover from dad
            child1=individual(World);
            child1.route=child1route;
            child1=determineFitness(child1,World);
            
            choice = randi([floor(x/3) ceil(2*x/3)],1,1);
            child2route = daddy(1,1:choice);
            routeTemp = mummy;
            for index= 1:choice
                value=daddy(index);
                routeTemp(routeTemp == value) = [];
            end
            child2route=[child2route,routeTemp];
            child2=individual(World);
            child2.route=child2route;
            child2=determineFitness(child2,World);
        end
        
        %Mutation method
        function [obj,offSpringArray] = Mutate(obj,offSpringArray)
           %this method performs mutation
           
           x = rand; 
           if x >0.66 %perform mutation 50% of time
               
               selection = randi([1 10],1,1); %select random offspring to mutate
               mutant = offSpringArray(selection); %get offspring as individual
               route = mutant.route; %get route
               rLength = length(route);
               
               %choose 2 elements in vector
               choice = randi([1 rLength],1,2); %%%HERE
               while choice(1)==choice(2)
                     choice(2) = randi([1 rLength],1,1); %ensure the choices are different elements
               end
               
               %perform swap
               y1 = route(choice(1)); 
               y2 = route(choice(2));
               route(choice(1)) = y2;
               route(choice(2)) = y1;
               
               mutant.route = route; %update route of individual
               offSpringArray(selection) = mutant;
               
           elseif x >0.33 %rotate part of route vector
               selection = randi([1 10],1,1); %select random offspring to mutate
               mutant = offSpringArray(selection); %get offspring as individual
               route = mutant.route; %get route
               rLength = length(route);
               
               choice = randi([floor(rLength/3) ceil(2*rLength/3)],1,1); %random number between 3 and 7.
               routeTemp = route(choice:end);
               routeTemp = flip(routeTemp);
               route(choice:end) = routeTemp;
               mutant.route = route; %update route of individual
               offSpringArray(selection) = mutant;
           end
           
        end
        
        %Cull population
        function obj = cullPop(obj, World)
            %this function removes the second half of the array
            
            %must remove duplicates
            pop = obj.popArray;
            
            index =1; %outer loop iteration count
            for x = 1:20 %check once for each individual
                ind = pop(index); %get individual
                CompRoute = ind.route; %get route for comparison
                
                count = 0; %set duplication count to 0
                innerIndex = 1; %inner loop iteration count
                for y = 1:20 %check population with each individual
                indtoCheck = pop(innerIndex); %get individual to check   
                CheckRoute = indtoCheck.route; %get route for comparison
                
                if CompRoute == CheckRoute
                    count = count+1; %if duplicate found, increase count
                    if count > 1 %always expect to find one duplicate, any more replace duplicate
                        pop(innerIndex)= individual(World); %create an individual 
                    end
                end

                innerIndex = innerIndex + 1;
                end
     
            index = index+1;                    
            end
            
            obj.popArray = pop;
            
            obj = sortFitness(obj); %order from best to worst
            obj.popArray = obj.popArray(1,1:10);
        end
    end
end

