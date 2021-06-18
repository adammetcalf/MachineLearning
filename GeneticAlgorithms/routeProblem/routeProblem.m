clc;
clear;


                    %%%%%%%%%%%% SETUP  %%%%%%%%%%%%

%Create problem space - Generate and plot world
WorldSize=15;
World = rand([WorldSize,2]).*1000;


bestInd = individual(World);

epoch = 1;
                   %%%%%%%%%%%% SETUP END %%%%%%%%%%%%
while epoch<100
    
%Create population of 10 individuals, and sort for fitness
population = population(World);
population.popArray(1) = bestInd;
oldFitness = 99999;
                    

                    
                    %%%%%%%%%%%% Evolve  %%%%%%%%%%%%
                    
    Evolution =1;
    convCheckCount =0;
    while convCheckCount < 50                  
    %get the best individual from the population
    [path,fitness,average] = getBest(population);
    convCheckin = fitness;

    evolutionCount(Evolution) = Evolution;
    allAverage(Evolution) = average;
    allFitness(Evolution) = fitness;
    
    if fitness < oldFitness
        for num=1:WorldSize
            nextCity = path(num);
            nextX(num) = World(nextCity,1);
            nextY(num) = World(nextCity,2);    
        end
    end
    
    [rpath,rfitness,raverage] = getRandom(population);
    
    for num=1:WorldSize
        nextCitydef = rpath(num);
        nextXdef(num) = World(nextCitydef,1);
        nextYdef(num) = World(nextCitydef,2);    
    end
    
    
    plotTitle = ["Epoch: "+ num2str(epoch) + " " + "Evolution: "+ num2str(Evolution)];
    fig = figure(1);
    fig.WindowState = 'fullscreen';
    subplot(1,3,1)   %plot fitness
    plot(evolutionCount,allAverage,evolutionCount,allFitness);
    title(plotTitle);
    
    subplot(1,3,2)
    plot(World(:,1),World(:,2),'kx',nextXdef,nextYdef)
    for x = 1:WorldSize
        txtt = num2str(x);
        txt2 ="  "+txtt;          
        text(nextXdef(x),nextYdef(x),txt2,'Color','red')
    end
    
    if fitness < oldFitness
        subplot(1,3,3)
        plot(World(:,1),World(:,2),'kx',nextX,nextY)
        for x = 1:WorldSize
            txtt = num2str(x);
            txt2 ="  "+txtt;          
            text(nextX(x),nextY(x),txt2,'Color','red')
        end
    end
    
    
    %breed population, mutate, cull
    population = breedPop(population,World); 
    
    [path2,fitness2,average2] = getBest(population);
    convCheckout = fitness2;
    if convCheckout == convCheckin
        convCheckCount = convCheckCount+1;
    else
        convCheckCount =0;
    end
    
    Evolution = Evolution+1;
    oldFitness = fitness;
    end
    clf(fig);
       
    bestInd = population.popArray(1);
    clear population evolutionCount allAverage allFitness
    epoch = epoch+1;
end

%%%%%%%%%%%% End Evolve  %%%%%%%%%%%%

close(fig)

bestRoute = bestInd.route;

for num=1:WorldSize
    nextCity = bestRoute(num);
    nextX(num) = World(nextCity,1);
    nextY(num) = World(nextCity,2);    
end


figure(2)
plot(World(:,1),World(:,2),'kx',nextX,nextY)
for x = 1:WorldSize
    txtt = num2str(x);
    txt2 ="  "+txtt;
    text(nextX(x),nextY(x),txt2,'Color','red')
end
            