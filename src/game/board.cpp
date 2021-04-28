//
// Created by Diego Santos Seabra on 21/04/21.
//

#include "board.h"
#include "../engine/resource_manager.h"

Board::Board()
{
}

void Board::init()
{
    // Initialize Renderer
    renderer2D = new Renderer2D();

    // Load atlas
    cardAtlas = SpriteAtlas(ResourceManager::LoadTexture("assets/atlas/atlas_cards.png"),
                            cardWidth, cardHeight);

    // Deck
    deck = new Deck();
    deck->mapCards();
    deck->mapFaceTypes();
    deck->shuffleCards();
    deck->position = {32.0f, 16.0f};
    deck->bounds = {deck->position, cardWidth, cardHeight};

    // Foundation Piles
    pileHearts = new FoundationPile();
    pileHearts->position = {272.0f, 16.0f};

    pileSpades = new FoundationPile();
    pileSpades->position = {352.0f, 16.0f};

    pileDiamonds = new FoundationPile();
    pileDiamonds->position = {432.0f, 16.0f};

    pileClubs = new FoundationPile();
    pileClubs->position = {512.0f, 16.0f};

    // Piles of Cards
    p1 = new CardPile();
    p1->position = {32.0f, 128.0f};

    p2 = new CardPile();
    p2->position = {112.0f, 128.0f};

    p3 = new CardPile();
    p3->position = {192.0f, 128.0f};

    p4 = new CardPile();
    p4->position = {272.0f, 128.0f};

    p5 = new CardPile();
    p5->position = {352.0f, 128.0f};

    p6 = new CardPile();
    p6->position = {432.0f, 128.0f};

    p7 = new CardPile();
    p7->position = {512.0f, 128.0f};

    // TODO: Play Draw Cards Animation
//    deck.drawCard();
}

void Board::update()
{
    deck->update();
}

void Board::render()
{
    batch.begin();
    deck->getTopCard();
//    batch.add(deck);
    batch.end();

    // Deck
    deck->render(renderer2D, &cardAtlas);

    // Foundation Piles
    pileHearts->render(renderer2D, &cardAtlas);
    pileSpades->render(renderer2D, &cardAtlas);
    pileDiamonds->render(renderer2D, &cardAtlas);
    pileClubs->render(renderer2D, &cardAtlas);

    // Card Piles
    p1->render(renderer2D, &cardAtlas);
    p2->render(renderer2D, &cardAtlas);
    p3->render(renderer2D, &cardAtlas);
    p4->render(renderer2D, &cardAtlas);
    p5->render(renderer2D, &cardAtlas);
    p6->render(renderer2D, &cardAtlas);
    p7->render(renderer2D, &cardAtlas);
}